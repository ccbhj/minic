#ifndef _AST_H_
#define _AST_H_

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>
#include <assert.h>

#include "tokens.h"

#define T2STR(t) (t == Type::int_ ? "int" : "void")

namespace ccbhj {
class Context;
class CodeGenContext;

////////////////////////////////////////////////////////
//
// Node is the base class for all kinds of ast tree node.
//
////////////////////////////////////////////////////////
class Node {
public:
  virtual ~Node() {}
  virtual void print(std::ostream &os, const size_t padding = 0) const = 0;

  static inline std::string get_indent(const size_t size) {
    return std::string(size * 2, ' ');
  }

  // implement this to generate code 
  virtual void gen_code(CodeGenContext &, Context &) {
    assert(false);
  }
};

// Expression Node
class ExpNode : public Node {
public:
  ExpNode() = default;
  virtual ~ExpNode() {}
};
using ExpList = std::vector<ExpNode *>;

// Statement Node
class StmtNode : public Node {
public:
  StmtNode() = default;
  virtual ~StmtNode() {}
};
using StmtList = std::vector<StmtNode *>;
// Expression evaluates to  a value, but statements don't

/*
    Build-in function Node
class BiFnNode: public StmtNode {
private:
    BFI functype;
    Node* arg;
public:
    BiFnNode(BFI functype, Node* arg)
        : arg(arg), functype(functype) {}
    ~BiFnNode() {
        delete arg;
    }

    void print(std::ostream &os, const size_t padding) const override {
        os << Node::get_indent(padding);
        switch (functype) {
            case BFI::B_read:
                os << "read" << std::endl;
                break;
            case BFI::B_write:
                os << "write" << std::endl;
                break;
        }
        arg->print(os, padding + 1);
    }
};
*/

class BlockNode : public StmtNode {
public:
  std::vector<StmtNode*> statements;
  BlockNode() {}
  ~BlockNode() {
    for (Node *s : statements) {
      delete s;
    }
  }
  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "BLOCK:" << std::endl;
    std::for_each(statements.begin(), statements.end(),
                  [&](StmtNode *s) { s->print(os, padding + 1); });
    os << get_indent(padding) << "ENDBLOCK" << std::endl;
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

// NumNode is a number type node.
class NumNode : public ExpNode {
public:
  int value;
  NumNode(int value) : value(value) {}
  ~NumNode() = default;
  void print(std::ostream &os, const size_t padding) const override {
    os << Node::get_indent(padding) << "int_const: " << value << std::endl;
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

class IdentifierNode : public ExpNode {
public:
  const std::string *name;
  const int lineno;
  IdentifierNode(const std::string *name, const int lineno) : name(name) , lineno(lineno) {}
  ~IdentifierNode() {
    if (name)
      delete name;
  }
  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "symbol: " << *name << std::endl;
  }

  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

class ArrayRef : public IdentifierNode {
public:
  ExpNode *index;
  ArrayRef(IdentifierNode *id, ExpNode *index): IdentifierNode(id->name, id->lineno), index(index) {}
  ~ArrayRef() { delete index; }

  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "array quote: " << std::endl;
    IdentifierNode::print(os, padding + 1);
    os << get_indent(padding + 1) << "index: " << std::endl;
    index->print(os, padding + 2);
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

class Formal : public StmtNode {
public:
  Type type_decl;
  IdentifierNode *id;

  Formal(int type_decl, IdentifierNode *id)
      : type_decl((Type)type_decl), id(id) {}
  ~Formal() { delete id; }
  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "formal: " << std::endl;
    os << get_indent(padding + 1) << "type: " << T2STR(type_decl) << std::endl;
    os << get_indent(padding + 1) << "ID: " << std::endl;
    id->print(os, padding + 2);
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

class ArrayFormal : public Formal {
public:
  int length;
  ArrayFormal(int typ, IdentifierNode *id, int len = 0) : Formal(typ, id), length(len) {}
  ~ArrayFormal() { }

  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "array: " << std::endl;
    Formal::print(os, padding + 1);
    if (length) 
      os << get_indent(padding + 1) << "length: " << length << std::endl;
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

class Formals : public StmtNode {
public:
  std::vector<Formal *> formals;
  Formals() {}
  ~Formals() {
    for (Formal *f : formals) {
      delete f;
    }
  }
  void print(std::ostream &os, const size_t padding) const override {
    std::for_each(formals.begin(), formals.end(),
                  [&](Formal *f) { f->print(os, padding + 1); });
  }

  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

class FuncDeclNode : public StmtNode {
public:
  IdentifierNode *name;
  Formals *formals = nullptr;
  Type ret_type;
  BlockNode *block;
  FuncDeclNode(int ret_type, IdentifierNode *name, Formals *formals,
               BlockNode *block)
    : name(name), formals(formals), ret_type((Type)ret_type), block(block) {}

  ~FuncDeclNode() {
    delete name;
    delete block;
    if (formals) {
      delete formals;
    }
  }
  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "function: " << std::endl;
    os << get_indent(padding + 1) << "name: " << std::endl;
    name->print(os, padding + 2);

    if (formals) {
      os << get_indent(padding + 1) << "formals" << std::endl;
      formals->print(os, padding + 2);
    }

    os << get_indent(padding + 1) << "return type: " << T2STR(ret_type)
       << std::endl;
    os << get_indent(padding + 1) << "body: " << std::endl;
    block->print(os, padding + 2);
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

class ReturnNode : public StmtNode {
public:
  ExpNode *expr;
  ReturnNode(ExpNode *expr = nullptr) : expr(expr) {}
  ~ReturnNode() {
    if (expr)
      delete expr;
  }

  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "return: " << std::endl;
    expr->print(os, padding + 1);
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

class ArgsNode : public ExpNode {
public:
  ExpList args;

  ArgsNode() : args() {}
  ~ArgsNode() {
    std::for_each(args.begin(), args.end(), [](ExpNode *e) {
      if (e)
        delete e;
    });
  }
  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "args: " << std::endl;
    std::for_each(args.begin(), args.end(),
                  [&](ExpNode *e) { e->print(os, padding + 1); });
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

class MethodCallNode : public ExpNode {
public:
  IdentifierNode *id = nullptr;
  ArgsNode *args = nullptr;
  MethodCallNode(IdentifierNode *id, ArgsNode *args = nullptr)
      : id(id), args(args) {}
  ~MethodCallNode() {
    delete id;
    if (args)
      delete args;
  }
  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "call method" << std::endl;
    id->print(os, padding + 1);
    if (args) {
      args->print(os, padding + 1);
    }
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

// SymRefNode is a reference of a symbol.
// AsgNode is a node representing '='
class AsgNode : public ExpNode {
public:
  IdentifierNode *id = nullptr;
  ExpNode *rhs = nullptr;
  AsgNode(IdentifierNode *id, ExpNode *exp) : id(id), rhs(exp) {}
  ~AsgNode() {
    delete id;
    delete rhs;
  }

  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding);
    os << "=" << std::endl;
    id->print(os, padding + 1);
    rhs->print(os, padding + 1);
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

// BinaryOperator represents binary operator,
// like '+', '-', '*', '/'
// and comparision '>', '<', '!=', '=', '<=', '>='
class BinaryOperator : public ExpNode {
public:
  BiOpt op;
  ExpNode *left = nullptr;
  ExpNode *right = nullptr;
  BinaryOperator(BiOpt op, ExpNode *l, ExpNode *r)
      : op(op), left(l), right(r) {}
  ~BinaryOperator() {
    if (left)
      delete left;
    if (right)
      delete right;
  }

  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding);
    std::string opt = "";
    switch (op) {
    case BiOpt::plus:
      opt = "+";
      break;
    case BiOpt::minus:
      opt = "-";
      break;
    case BiOpt::div:
      opt = "/";
      break;
    case BiOpt::mul:
      opt = "*";
      break;
    case BiOpt::less:
      opt = "<";
      break;
    case BiOpt::greater:
      opt = ">";
      break;
    case BiOpt::equal:
      opt = "==";
      break;
    case BiOpt::nequal:
      opt = "!=";
      break;
    case BiOpt::eless:
      opt = "<=";
      break;
    case BiOpt::egreater:
      opt = ">=";
      break;
    }
    os << opt << std::endl;
    left->print(os, padding + 1);
    right->print(os, padding + 1);
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

class UnaryOperator : public ExpNode {
public:
  UaOpt opt;
  ExpNode *target;
  UnaryOperator(UaOpt opt, ExpNode *target) : opt(opt), target(target) {}
  ~UnaryOperator() { delete target; }

  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding);
    std::string sym = "";
    switch (opt) {
    case UaOpt::neg:
      sym = "-";
      break;
    }
    os << sym << std::endl;
    target->print(os, padding + 1);
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

class ExpStmtNode : public ExpNode, public StmtNode {
public:
  ExpNode *expr;
  ExpStmtNode(ExpNode *expr) : expr(expr) {}
  void print(std::ostream &os, const size_t padding = 0) const override {
    if (expr)
      expr->print(os, padding);
  }
  ~ExpStmtNode() { delete expr; }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override {
    expr->gen_code(code_ctx, ast_ctx);
  }
};

class WhileNode : public StmtNode {
public:
  ExpNode *cond;
  StmtNode *th;
  WhileNode(ExpNode *cond, StmtNode *th = nullptr) : cond(cond), th(th) {}
  ~WhileNode() {
    delete cond;
    if (th)
      delete th;
  }
  void print(std::ostream &os, const size_t padding = 0) const override {
    os << get_indent(padding) << "WHILE:" << std::endl;
    cond->print(os, padding + 1);
    if (th) {
      os << get_indent(padding) << "DO:" << std::endl;
      th->print(os, padding + 1);
    }
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};

/*
class ForNode : public StmtNode {
public:
  bool is_incr;
  AsgNode *start;
  ExpNode *end;
  BlockNode *th;
  explicit ForNode(bool is_incr, AsgNode *start, ExpNode *end,
                   BlockNode *th = nullptr)
      : is_incr(is_incr), start(start), end(end), th(th) {}
  ~ForNode() {
    delete start;
    delete end;
    if (th)
      delete th;
  }
  void print(std::ostream &os, const size_t padding = 0) const override {
    os << get_indent(padding) << "FOR: " << std::endl;
    start->rhs->print(os, padding + 2);
    os << get_indent(padding + 1) << "FROM " << std::endl;
    start->lhs->print(os, padding + 2);
    if (is_incr)
      os << get_indent(padding + 1) << "TO" << std::endl;
    else
      os << get_indent(padding + 1) << "DOWNTO" << std::endl;
    end->print(os, padding + 2);
    os << get_indent(padding + 1) << "DO" << std::endl;
    th->print(os, padding + 2);
    os << get_indent(padding + 1) << "ENDDO" << std::endl;
  }
};
*/

class SelectNode : public StmtNode {
public:
  ExpNode *cond = nullptr;
  StmtNode *th = nullptr;
  StmtNode *el = nullptr;
  SelectNode() {}
  SelectNode(ExpNode *cond, StmtNode *th, StmtNode *el = nullptr)
      : cond(cond), th(th), el(el) {}
  ~SelectNode() {
    delete cond;
    delete th;
    if (el)
      delete el;
  }

  void print(std::ostream &os, const size_t padding) const override {
    os << Node::get_indent(padding) << "IF: " << std::endl;
    cond->print(os, padding + 1);
    if (th != nullptr) {
      os << Node::get_indent(padding) << "THEN: " << std::endl;
      th->print(os, padding + 1);
    }
    if (el != nullptr) {
      os << Node::get_indent(padding) << "ELSE: " << std::endl;
      el->print(os, padding + 1);
    }
  }
  void gen_code(CodeGenContext &code_ctx, Context &ast_ctx) override;
};


} // namespace ccbhj
#endif // _AST_
