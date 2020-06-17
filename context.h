#ifndef TINYCTX_H_
#define TINYCTX_H_

#include <map>
#include <string>
#include <vector>
#include <ostream>
#include <stack>
#include "ast.h"
#include "tokens.h"

namespace ccbhj {

struct VarEntry {
  Type typ;
  int lineno;
  // 如果是变量entry, 那么此offset指离fp(或者gp)的offset
  // 全局变量与形参时为正, 局部变量为负
  // 如果是函数, 那么offset指函数的位置(eloc)
  // 注意: 因为栈是向下增长的, 所以offset必须是非正数.
  int offset; 
  // 如果变量是数组, 那么还要存储长度
  int length;
};

struct FuncEntry {
  std::map<std::string, VarEntry> params;
  VarEntry meta_data;
};
////////////////////////////////////////////////////////
//
// Context为ast的上下文
//
///////////////////////////////////////////////////////
//
using VarTable = std::map<std::string, VarEntry>;

using FuncScope = std::vector<VarTable>;
class Context {
public:
  // ast's root
  BlockNode* programBlock = nullptr;

  // 当前函数的作用域
  std::stack<FuncScope> func_scopes;
  
  // 存储函数表
  std::map<std::string, FuncEntry> func_table;

  VarTable global_var_table;

  bool is_debug = false;
  bool has_return = false;

  ~Context() {
    if ( programBlock ) {
      delete programBlock;
    }
  }

  void print(std::ostream& os) {
    if (!programBlock)
      return;
    for (auto s: programBlock->statements) {
      s->print(os, 0);
    }
  }

  void set_debug(bool debug) {
    this->is_debug = debug;
  }
  void pdebug(const std::string msg) {
    if (is_debug)
      std::cout <<  msg << std::endl;
  }

  inline void new_func_scope() {
    FuncScope func_scope;
    func_scopes.push(func_scope);
    pdebug("push new function scope");
    has_return = false;
    new_scope(); // base scope
  }

  inline FuncScope &current_func_scope() {
    return func_scopes.top();
  }


  inline void pop_func_scope() {
    pdebug("pop function scope");
    func_scopes.pop();
  }

  inline void new_scope() {
    VarTable tab;
    func_scopes.top().push_back(tab);
    pdebug("push new block scope");
  }

  inline VarTable &current_scope() {
    return current_func_scope().back();
  }

  inline void pop_scope() {
    VarTable &current_func = current_scope();
    if (is_debug)
      for (auto it = current_func.begin(); it != current_func.end(); it++) {
        pdebug("pop" + it->first );
      }
    func_scopes.top().pop_back();
    pdebug("pop block scope");
  }

  const VarEntry* lookup_var(const std::string &name) {
    if (func_scopes.empty())
      return nullptr;
    FuncScope &current_func = func_scopes.top();
    for (int i = current_func.size() - 1; i >= 0; i--) {
        auto fi = current_func.at(i).find(name);
        if (fi != current_func.at(i).end())
          return &fi->second;
    }
    return nullptr;
  }

  const VarEntry* lookup_global_var(const std::string &name) {
    auto it = global_var_table.find(name);
    if (it != global_var_table.end()) 
      return &it->second;
    return nullptr;
  }

  bool add_var_in_scope(const std::string &name, VarEntry &entry) {
    FuncScope &current_func = func_scopes.top(); 
    VarTable &tab = current_func.back();
    if (tab.find(name) != tab.end()) {
      return false;
    }
    tab.emplace(std::make_pair(name, entry));
    pdebug("push " + name);
    return true;
  }

  inline bool is_global_scope() {
    return func_scopes.empty();
  }

  // add_var_in_global 添加一个全局变量
  // 若在一个函数作用域内添加, 添加失败且返回-2
  // 若变量已存在, 添加失败且返回-1
  inline int add_var_in_global(const std::string &name, VarEntry &entry) {
    auto it = global_var_table.find(name);
    if (!is_global_scope()) {
      return -2;
    }
    if (it != global_var_table.end()) {
      return -1;
    } 
    global_var_table.emplace(std::make_pair(name, entry));
    pdebug("add global var "+ name);
    return 1;
  }

  inline int add_func(const std::string &name, FuncEntry &entry) {
    if (func_table.find(name) != func_table.end())
      return 0;
    func_table.emplace(std::make_pair(name, entry));
    pdebug("add function " + name);
    return 1;
  }
};
}
#endif // ! TINYCTX_H_
