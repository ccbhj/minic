#include "code_gen_ctx.h"
#include "context.h"
#include <cassert>

using namespace ccbhj;


void NumNode::gen_code(CodeGenContext &code_ctx, Context &) {
  code_ctx.print_debug("-> Const " + std::to_string(value));
  code_ctx.RM_ins("LDC", ac, this->value, 0, "load const"); 
  code_ctx.print_debug("<- Const");
}

void IdentifierNode::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  code_ctx.print_debug("-> ID " + *name);
  const VarEntry *entry = ast_ctx.lookup_var(*name);
  if (!entry) {
    entry = ast_ctx.lookup_global_var(*name);
    if (!entry) {
      code_ctx.print_err("id " + *name + " not found");
      goto out;
    }
    // 获取地址
    code_ctx.RM_ins("LDA", ac, entry->offset, gp, "load global var memory");
  } else {
    code_ctx.RM_ins("LDA", ac, entry->offset, fp, "load local var memory");
  }
  if (entry->typ == Type::array_ref)  {
    code_ctx.RM_ins("LDA", ac, entry->offset, fp, "load refered array memory"); 
  }
  if (entry->typ == Type::array_ && code_ctx.state.get_addr_if_array)
    goto out;
  if (code_ctx.state.get_val) {
    code_ctx.RM_ins("LD", ac, 0, ac, "load id value");
  }
out:
  code_ctx.print_debug("<- ID");
}

void AsgNode::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  code_ctx.print_debug("-> assign ");
  const VarEntry* entry = ast_ctx.lookup_var(*id->name);
  CodeGenContext::State old_state(code_ctx.state);
  if (!entry) {
    entry = ast_ctx.lookup_global_var(*id->name);
    if (!entry) {
      code_ctx.print_err("address not found");
      goto out;
    }
  } 
  if(entry->typ == Type::void_) {
    code_ctx.print_err("invalid assignment");
    goto out;
  } 

  code_ctx.set_state(false, false);
  id->gen_code(code_ctx, ast_ctx); // store left value's address in ac1
  code_ctx.RM_ins("ST", ac, code_ctx.tmp_offset--, fp, "push left value");
  code_ctx.RM_ins("LDA", mp, -1, mp, "grow stack");

  code_ctx.set_state(true, false);
  rhs->gen_code(code_ctx, ast_ctx); // store right value in ac
  
  // 因为ac1中的左值可能丢失(被右值生成使用)
  // 所以需要从内存再load一次
  code_ctx.RM_ins("LD", ac1, ++code_ctx.tmp_offset, fp, "load left value again");
  code_ctx.RM_ins("LDA", mp, 1, mp, "shrink stack");

  // then assign
  code_ctx.RM_ins("ST", ac, 0, ac1, "assign: store value");

out:
  code_ctx.state = old_state;
  code_ctx.print_debug("<- assign");
}

void BinaryOperator::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  code_ctx.print_debug("-> BOp");
  CodeGenContext::State old_state(code_ctx.state);
  code_ctx.set_state(true, false);
  left->gen_code(code_ctx, ast_ctx);

  code_ctx.RM_ins("ST", ac, code_ctx.tmp_offset--, fp,"push left operand");
  code_ctx.RM_ins("LDA", mp, -1, mp, "grow stack");

  right->gen_code(code_ctx, ast_ctx);
  code_ctx.state = old_state;
  code_ctx.RM_ins("LD", ac1, ++code_ctx.tmp_offset , fp , "recover left operand");
  code_ctx.RM_ins("LDA", mp, 1, mp, "grow stack");
  switch (op) {
  case BiOpt::plus:
    code_ctx.RO_ins("ADD", ac, ac1, ac, "op +");
    break;
  case BiOpt::minus:
    code_ctx.RO_ins("SUB", ac, ac1, ac, "op -");
    break;
  case BiOpt::mul:
    code_ctx.RO_ins("MUL", ac, ac1, ac, "op *");
    break;
  case BiOpt::div:
    code_ctx.RO_ins("DIV", ac, ac1, ac, "op /");
    break;
  case BiOpt::less:
    code_ctx.RO_ins("SUB", ac, ac1, ac, "op <");
    code_ctx.RM_ins("JLT", ac, 2, pc, "br if true");
    // ac = 0 
    code_ctx.RM_ins("LDC", ac, 0, 0, "false case");  
    // ac = pc + 1
    code_ctx.RM_ins("LDA", pc, 1, pc, "unconditional jmp");
    // ac = 1
    code_ctx.RM_ins("LDC", ac, 1, 0, "true case");
    break;
  case BiOpt::equal:
    code_ctx.RO_ins("SUB", ac, ac1, ac, "op ==");
    code_ctx.RM_ins("JEQ", ac, 2, pc, "br if true");
    code_ctx.RM_ins("LDC", ac, 0, 0, "false case");
    code_ctx.RM_ins("LDA", pc, 1, pc, "unconditional jmp");
    code_ctx.RM_ins("LDC", ac, 1, 0, "true case");
    break;
  case BiOpt::nequal:
    code_ctx.RO_ins("SUB", ac, ac1, ac, "op !=");
    code_ctx.RM_ins("JNE", ac, 2, pc, "br if true");
    code_ctx.RM_ins("LDC", ac, 0, 0, "false case");
    code_ctx.RM_ins("LDA", pc, 1, pc, "unconditional jmp");
    code_ctx.RM_ins("LDC", ac, 1, 0, "true case");
    break;

  case BiOpt::greater:
    code_ctx.RO_ins("SUB", ac, ac1, ac, "op >");
    code_ctx.RM_ins("JGT", ac, 2, pc, "br if true");
    code_ctx.RM_ins("LDC", ac, 0, 0, "false case");
    code_ctx.RM_ins("LDA", pc, 1, pc, "unconditional jmp");
    code_ctx.RM_ins("LDC", ac, 1, 0, "true case");
    break;
  case BiOpt::eless:
    code_ctx.RO_ins("SUB", ac, ac1, ac, "op <=");
    code_ctx.RM_ins("JLE", ac, 2, pc, "br if true");
    code_ctx.RM_ins("LDC", ac, 0, 0, "false case");
    code_ctx.RM_ins("LDA", pc, 1, pc, "unconditional jmp");
    code_ctx.RM_ins("LDC", ac, 1, 0, "true case");
    break;
  case BiOpt::egreater:
    code_ctx.RO_ins("SUB", ac, ac1, ac, "op >=");
    code_ctx.RM_ins("JGE", ac, 2, pc, "br if true");
    code_ctx.RM_ins("LDC", ac, 0, 0, "false case");
    code_ctx.RM_ins("LDA", pc, 1, pc, "unconditional jmp");
    code_ctx.RM_ins("LDC", ac, 1, 0, "true case");
    break;
  default:
    // unreachable
    assert(false);
    code_ctx.print_err("unknown operator");
  }
  code_ctx.print_debug("<- BOp");
}

void UnaryOperator::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  code_ctx.print_debug("-> UOp");
  this->target->gen_code(code_ctx, ast_ctx);
  switch (this->opt) {
    case UaOpt::neg:
      code_ctx.RM_ins("LDC", ac1, -1, 0, "load -1");
      code_ctx.RO_ins("MUL", ac, ac1, ac, "mul -1");
      break;
  }
  target->gen_code(code_ctx, ast_ctx);
  code_ctx.print_debug("<- UOp");
}


void WhileNode::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  ast_ctx.new_scope();
  code_ctx.print_debug("-> while");

  int saved_loc_1 = code_ctx.skip(0);
  code_ctx.print_debug("jump here after body");
  this->cond->gen_code(code_ctx, ast_ctx);

  int saved_loc_2 = code_ctx.skip(1);
  th->gen_code(code_ctx, ast_ctx);
  code_ctx.RM_ins("LDC", pc, saved_loc_1, 0, "jump to cond");

  int current_loc = code_ctx.skip(0);
  code_ctx.backup(saved_loc_2);
  code_ctx.print_debug("jump here if cond returns false");

  code_ctx.RM_ins("JEQ", ac, current_loc, 0, "jump to end");
  code_ctx.restore();
  code_ctx.print_debug("<- while");
  ast_ctx.pop_scope();
}

void SelectNode::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  ast_ctx.new_scope();
  code_ctx.print_debug("-> if");

  // gen condition and skip 
  cond->gen_code(code_ctx, ast_ctx);
  int cond_loc1 = code_ctx.skip(1);
  code_ctx.print_debug("if: jmp to else belongs here");
  
  // gen then body and skip 
  th->gen_code(code_ctx, ast_ctx);
  int then_loc = code_ctx.skip(1);
  code_ctx.print_debug("if: jmp to end belongs here");

  int current_loc = code_ctx.skip(0); // get current location 
  code_ctx.backup(cond_loc1); // backup condition  location
  code_ctx.RM_Abs_ins("JEQ", ac, current_loc, "if: jmp to else");
  code_ctx.restore(); 

  if (el) {
    el->gen_code(code_ctx, ast_ctx);
  }
  current_loc = code_ctx.skip(0);
  code_ctx.backup(then_loc);
  code_ctx.RM_Abs_ins("LDA", pc, current_loc, "jmp to end");
  code_ctx.restore();

  code_ctx.print_debug("<- if");
  ast_ctx.pop_scope();
}

void Formal::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  code_ctx.print_debug("-> var declaration");
  // don't call id->gen_code() here
  // we don't expect it to load value or address
  const VarEntry *entry = ast_ctx.lookup_var(*id->name);
  if (entry) {
    code_ctx.print_err(std::string("value" + *id->name + " has already declared at " + std::to_string(id->lineno)).c_str());
    return;
  } else {
    // global variable 
    if (ast_ctx.is_global_scope()) {
      int of = ast_ctx.global_var_table.size();
      // global variable is stored below the gp 
      // so its offset must be negative or zero.
      VarEntry entry {
        .typ = type_decl,
        .lineno = id->lineno,
        .offset = -of,
        .length = 1
      };
      ast_ctx.add_var_in_global(*id->name, entry);
      return;
    } 
    // local variable
    assert(code_ctx.tmp_offset <= -2);
    VarEntry entry {
      .typ = type_decl,
      .lineno = id->lineno,
      .offset = code_ctx.tmp_offset--,
      .length = 1
    };
    ast_ctx.add_var_in_scope(*id->name, entry);

    // alloc var in memory
    // ac must be set to 0
    code_ctx.RM_ins("LDA", mp, -1, mp, "grow stack");
  }
  code_ctx.print_debug("<- var declaration");
}

void ArrayFormal::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  code_ctx.print_debug("<- array declaration");
  const VarEntry *entry = nullptr;
  VarEntry e;
  if (ast_ctx.is_global_scope()) {
    entry = ast_ctx.lookup_global_var(*id->name);
    if (entry) {
      code_ctx.print_err("value" + *id->name + " has already declared in global  at " + std::to_string(id->lineno));
      goto out;
    }
    e.typ = type_decl;
    e.lineno = id->lineno;
    e.offset = 0;
    e.length = this->length;
    for (auto it = ast_ctx.global_var_table.cbegin();
        it != ast_ctx.global_var_table.cend();
        it++)
      e.offset -= it->second.length;
    e.offset -= (this->length - 1);
    ast_ctx.add_var_in_global(*id->name, e);
    code_ctx.RM_ins("LDA", mp, e.offset, gp, "grow stack");
  } else {
    entry = ast_ctx.lookup_var(*id->name);
    if (entry) {
      code_ctx.print_err("value" + *id->name + " has already declared at " + std::to_string(id->lineno));
      goto out;
    } else {
      assert(code_ctx.tmp_offset <= -2);
      code_ctx.tmp_offset -= length;
      e.typ = type_decl;
      e.lineno = id->lineno,
      e.offset = code_ctx.tmp_offset,
      e.length = this->length;
      code_ctx.tmp_offset--; 
      ast_ctx.add_var_in_scope(*id->name, e);

      code_ctx.RM_ins("LDA", mp, -(length + 1), mp, "grow stack");
    }
  }
out:
  code_ctx.print_debug("-> array declaration");
}

void ArrayEle::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  code_ctx.print_debug("-> array element");
  const VarEntry *p = ast_ctx.lookup_var(*this->name);
  CodeGenContext::State old_state(code_ctx.state);
  bool is_global = false;
  if (!p ) {
    p = ast_ctx.lookup_global_var(*this->name);
    if (!p)  {
      code_ctx.print_err("array not declared");
      goto out;
    } else {
      is_global = true;
    }
  }

  if (p->typ != Type::array_&& p->typ != Type::array_ref) {
    code_ctx.print_err(*this->name + " is not a array");
    goto out;
  }
  code_ctx.set_state(true, false);
  index->gen_code(code_ctx, ast_ctx); // put index in ac
  code_ctx.state = old_state;
  // 这里数组可能越界
  code_ctx.RM_ins("LDA", ac1, 0, ac, "copy index to ac1");
  if (is_global)
    code_ctx.RM_ins("LDA", ac, p->offset, gp, "load global array addr");
  else 
    code_ctx.RM_ins("LDA", ac, p->offset, fp, "load array addr");
  if (p->typ == Type::array_ref) {
    code_ctx.RM_ins("LD", ac, 0, ac, "load referred array addr");
  }
  code_ctx.RO_ins("ADD", ac, ac1, ac, "add offset");

  if (code_ctx.state.get_addr_if_array)
    goto out;
  if (code_ctx.state.get_val) 
    code_ctx.RM_ins("LD", ac, 0, ac, "load value");
out:
  code_ctx.print_debug("<- array element");
}

void BlockNode::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  // 调用前要新建作用域
  for (Node* n : statements)
    n->gen_code(code_ctx, ast_ctx);

  
  // 退出时要弹出所有作用域内的变量
  int var_count  = 0;
  if (!ast_ctx.current_func_scope().empty())
    for (auto &p : ast_ctx.current_scope())  {
      if (p.second.typ == Type::array_) {
        var_count += p.second.length;
      } else {
        var_count++;
      }
    }
  code_ctx.tmp_offset += var_count;
  code_ctx.RM_ins("LDA", mp, var_count, mp, "shrink stack");
}

void Formals::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  assert(code_ctx.tmp_offset <= -2);
  for (Formal *p: this->formals) {
    if (ast_ctx.lookup_var(*p->id->name)) {
      code_ctx.print_err("param name repulicated");
      continue;
    }

    p->gen_code(code_ctx, ast_ctx);
  }
}

void FuncDeclNode::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  code_ctx.print_debug("-> function declaration " + *name->name);
  if (*this->name->name == "main")  {
    code_ctx.main_func_offset = code_ctx.skip(0);
  }
  // check table
  auto it = ast_ctx.func_table.find(*name->name);
  if (it != ast_ctx.func_table.end())  {
    code_ctx.print_err("function already declared");
    code_ctx.print_debug("<- function declaration");
    return;
  }
  FuncEntry entry;
  entry.meta_data.lineno = name->lineno;
  entry.meta_data.typ = ret_type;
  entry.meta_data.offset = code_ctx.skip(0); 

  ast_ctx.new_func_scope();
  code_ctx.RM_ins("ST", ac, -1, fp, "store return point");
  std::map<std::string, VarEntry> &arg_tab = entry.params;
  int i = 1;
  if (formals)
    for (Formal* p: formals->formals) {
      VarEntry ventry;
      ventry.lineno = p->id->lineno;
      ventry.offset = i++; // not know yet
      ventry.typ = p->type_decl;
      if (arg_tab.find(*p->id->name) != arg_tab.end()) {
        code_ctx.print_err("argument has declaration");
        return;
      } 
      if (ventry.typ == Type::array_)
        ventry.length = ((ArrayFormal*)p)->length;
      arg_tab.emplace(std::make_pair(*p->id->name, ventry));
      ast_ctx.add_var_in_scope(*p->id->name, ventry);
    }

  ast_ctx.add_func(*name->name, entry);

  const int cur_tmp_offset = code_ctx.tmp_offset;
  code_ctx.tmp_offset = -2;
  block->gen_code(code_ctx, ast_ctx);
  code_ctx.tmp_offset = cur_tmp_offset;
  
  ast_ctx.pop_func_scope();
  if (!ast_ctx.has_return ) {
    if (entry.meta_data.typ != Type::void_)  {
      code_ctx.print_err("function: " + *name->name + " need return statement");
    } else {
      ReturnNode *ret = new ReturnNode(nullptr);
      ret->gen_code(code_ctx, ast_ctx);
      delete ret;
    }
  }

  code_ctx.print_debug("<- function declaration");
}

void MethodCallNode::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  code_ctx.print_debug("-> function call");
  CodeGenContext::State old_state(code_ctx.state);
  if (*id->name == "output" && this->args->args.size() == 1) {
    code_ctx.set_state(true, false);
    this->args->args.at(0)->gen_code(code_ctx, ast_ctx);
    code_ctx.RO_ins("OUT", ac, 0, 0, "write ac");
    code_ctx.print_debug("<- function call");
    return;
  } else if (*id->name == "input") {
    code_ctx.RO_ins("IN",  ac, 0, 0, "read integer value to ac");
    code_ctx.print_debug("<- function call");
    return;
  }
  auto it = ast_ctx.func_table.find(*id->name);
  if (it == ast_ctx.func_table.end()) {
    code_ctx.print_err("function not declared");
    code_ctx.print_debug("<- function call");
    return;
  } 
  if(args) {
    // check args' count
    if (args->args.size() != it->second.params.size()) {
      code_ctx.print_err("args not match");
      code_ctx.print_debug("<- function call");
      return;
    } 
  }
  // 参数是在fp上面的
  // 所以其offset为整数且非0(0为fp的位置)
  // 且第一个参数在低地址(离fp最近), 最后一个参数在高地址
  if (args) {
    // code_ctx.RM_ins("LDA", mp, -args->args.size(), mp, "grow stack for args");
    code_ctx.state.get_addr_if_array = true;
    for (auto it = args->args.rbegin(); it != args->args.rend(); it++) {
      (*it)->gen_code(code_ctx, ast_ctx); // calculate arg and store in ac
      code_ctx.RM_ins("ST", ac, code_ctx.tmp_offset--, fp, "push param");
      code_ctx.RM_ins("LDA", mp, -1, mp, "grow stack");
    }
  }

  code_ctx.RM_ins("ST", fp , 0, mp, "push ofp"); 
  code_ctx.RM_ins("LDA", fp, 0, mp, "reset current fp");
  code_ctx.RM_ins("LDA", mp, -2, mp, "grow stack for ofp and ret");
  
  // now store the return point in ac
  code_ctx.RM_ins("LDA", ac, 1, pc, "store return point");
  // jump to function
  code_ctx.RM_ins("LDC", pc, it->second.meta_data.offset, 0, "jump to function" );

  // pop args 
  if (args) {
    code_ctx.RM_ins("LDA", mp, args->args.size(), mp, "shrink stack for args");
    code_ctx.tmp_offset += args->args.size();
  }

  code_ctx.state = old_state;
  code_ctx.print_debug("<- function call");
}

void ArgsNode::gen_code(CodeGenContext &, Context &) {
  // every thing is done above.
}

void ReturnNode::gen_code(CodeGenContext &code_ctx, Context &ast_ctx) {
  code_ctx.print_debug("-> return");
  CodeGenContext::State old_state = code_ctx.state;
  code_ctx.set_state(true, false);
  if (expr) {
    expr->gen_code(code_ctx, ast_ctx); // load value into ac;
  }
  code_ctx.state = old_state;

  code_ctx.RM_ins("LDA", mp, 0, fp, "shrink stack");
  code_ctx.RM_ins("LD", fp, 0, fp, "restore fp");
  code_ctx.RM_ins("LD", pc, -1, mp, "load return point in pc" );
  ast_ctx.has_return = true;
  code_ctx.print_debug("<- return");
}
