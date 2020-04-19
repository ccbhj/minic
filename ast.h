#ifndef _AST_
#define _AST_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

#include "tokens.h"

namespace ccbhj {

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

// Formal Node
// 形参
class FormalNode : public Node {
public:
  FormalNode() = default;
  ~FormalNode() = default;
};

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

// NumNode is a number type node.
class NumNode : public ExpNode {
public:
  int value;
  NumNode(int value) : value(value) {}
  ~NumNode() = default;
  void print(std::ostream &os, const size_t padding) const override {
    os << Node::get_indent(padding) << "int_const: " << value << std::endl;
  }
};

class BlockNode : public ExpNode {
public:
  StmtList statements;
  BlockNode() {}
  ~BlockNode() {
    for (StmtNode *s : statements) {
      delete s;
    }
  }
  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "BLOCK:" << std::endl;
    for (StmtNode *n : statements) {
      n->print(os, padding + 1);
    }
    os << get_indent(padding) << "ENDBLOCK" << std::endl;
  }
};

class IdentifierNode : public ExpNode {
public:
  const std::string name;
  IdentifierNode(const std::string &name) : name(name) {}
  ~IdentifierNode() = default;
  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "symbol: " << name << std::endl;
  }
};

class Formal : public FormalNode {
public:
  IdentifierNode *type_decl;
  IdentifierNode *id;
  Formal(IdentifierNode *type_decl, IdentifierNode *id)
      : type_decl(type_decl), id(id) {}
  ~Formal() {
    delete type_decl;
    delete id;
  }
  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "formal: " << std::endl;
    type_decl->print(os, padding + 1);
    id->print(os, padding + 1);
  }
};

using Formals = std::vector<Formal>;

class FuncDeclNode : public StmtNode {
public:
  IdentifierNode *name;
  Formals formals;
  IdentifierNode *ret_type;
  ExpList expr;
  FuncDeclNode(IdentifierNode *name, Formals formals, IdentifierNode* ret_type, ExpList expr )
    : name(name), formals(formals), ret_type(ret_type), expr(expr)  { }

  ~FuncDeclNode() {
    delete name;
    std::for_each(
        formals.begin(), formals.end(),
        [](const  Formal *formal) { delete formal;} );
    delete ret_type;
    std::for_each(
        expr.begin(), expr.end(),
        [](const ExpNode *expr) {delete expr; });
  }
  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding) << "function: " << std::endl;
    os << get_indent(padding + 1) << "name: " << std::endl;
    name->print(os, padding + 2);

    os << get_indent(padding + 1) << "formals" << std::endl;
    std::for_each(
        formals.begin(), formals.end(),
        [&os, padding](const Formal formal) { formal.print(os, padding + 2); });

    os << get_indent(padding + 1) << "return type: " << std::endl;
    ret_type->print(os, padding + 2);

    os << get_indent(padding + 1) << "body: " << std::endl;
    std::for_each(
        expr.begin(), expr.end(),
        [&os, padding](const ExpNode *exp) { exp->print(os, padding + 2); });
  }
};

class MethodCallNode : public ExpNode {
public:
  IdentifierNode *id = nullptr;
  ExpList *args = nullptr;
  MethodCallNode(IdentifierNode *id, ExpList *args = nullptr)
      : id(id), args(args) {}
  ~MethodCallNode() {
    delete id;
    if (args)
      delete args;
  }
};
// SymRefNode is a reference of a symbol.
// AsgNode is a node representing ':='
class AsgNode : public ExpNode {
public:
  IdentifierNode *lhs = nullptr;
  ExpNode *rhs = nullptr;
  AsgNode(IdentifierNode *id, ExpNode *exp) : lhs(id), rhs(exp) {}
  ~AsgNode() {
    delete lhs;
    delete rhs;
  }

  void print(std::ostream &os, const size_t padding) const override {
    os << get_indent(padding);
    os << ":=" << std::endl;
    lhs->print(os, padding + 1);
    rhs->print(os, padding + 1);
  }
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
};

class ExpStmtNode : public StmtNode {
public:
  ExpNode *exp;
  ExpStmtNode(ExpNode *exp) : exp(exp) {}
  void print(std::ostream &os, const size_t padding = 0) const override {
    exp->print(os, padding);
  }
  ~ExpStmtNode() { delete exp; }
};

class WhileNode : public StmtNode {
public:
  ExpNode *cond;
  BlockNode *th;
  WhileNode(ExpNode *cond, BlockNode *th = nullptr) : cond(cond), th(th) {}
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
};

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

class SelectNode : public StmtNode {
public:
  ExpNode *cond = nullptr;
  BlockNode *th = nullptr;
  BlockNode *el = nullptr;
  SelectNode() {}
  SelectNode(ExpNode *cond, BlockNode *th, BlockNode *el = nullptr)
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
};

} // namespace ccbhj
#endif // _AST_
