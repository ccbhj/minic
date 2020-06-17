#ifndef _CODE_GEN_CTX_H
#define _CODE_GEN_CTX_H

#include "context.h"
#include <cassert>
#include <cstdio>
#include <ostream>
#include <fstream>
#include <cstring>


namespace ccbhj {

// 以下是一些寄存器
// 程序计数器
const int pc = 7;
// 内存指针
const int mp = 6;
// gp 总是指向最大的地址
const int gp = 5;
// 2个累加器
const int ac = 0;  // 优先用于存储值
const int ac1 = 1; // 优先用于存地址

// 当前函数栈底指针
const int fp = 3;

class CodeGenContext {

private:
  std::ostream *output = &std::cout; 
  bool is_debug;

public:
  Context *ast_ctx;
  // emitLoc
  // 指令执行位置
  int eloc = 0;
  // highEmitLoc
  int highloc = 0;

  // 内存栈顶的距离fp的指针, 用于保存记录临时变量的位置, 所以必须小于等于-2
  // 对于一个tmp_offset, 其内存地址可用 fp + tmp_offset来获取
  // 当压栈时, 调用RM_ins("ST", reg, tmp_offset--, fp, "")即可
  // 出栈则为RM_ins("LD", reg, ++tmp_offset, fp, "")
  int tmp_offset = 0;
  
  // main函数开始的位置(为一个指令号)
  int main_func_offset = 0 ;

  const static  size_t LINE_SIZE = 1024;
  
  struct State {
    // 当get_val为true时, 获取变量的值, 而不是地址
    bool get_val = false;
    
    // 当get_addr_if_array为true时, 只对数组求地址
    // 用在函数调用时数组传参
    // 当然如果get_val为false, 那么此域也没必要设为true 
    bool get_addr_if_array = false;
    State() = default;
    State(State& state) {
      this->get_addr_if_array = state.get_addr_if_array;
      this->get_val = state.get_val;
    }
    void operator = (const State &other) {
      this->get_addr_if_array = other.get_addr_if_array;
      this->get_val = other.get_val;
    }
  };
  State state;
public:
  explicit CodeGenContext(Context *ctx) : ast_ctx(ctx) { }

  ~CodeGenContext() {
    if (output != &std::cout)
      delete output;
  }
  
  inline void set_out(std::string &output) {
    if (output == "cout") {
      this->output = &std::cout;
      return;
    }
    std::ostream *os = new std::ofstream(output);
    this->output = os;
  }
  
  inline void set_debug(bool debug) {
    this->is_debug = debug;
  }

  inline void print_err(const std::string &msg) {
    RO_ins("HALT", 0, 0, 0, "");
    std::cerr << msg << std::endl;
  }


  // 输出指令到文件
  void print_buf(const std::string &str, const std::string &comment) {
    (*output) << str ;
    if (is_debug)
      (*output) << "   # " << comment;
    (*output)<< std::endl;
  }

  void print_debug(const std::string &comment) {
    if (is_debug)
      (*output) << "# " << comment << std::endl;
  }
  

  inline void set_state(bool get_val, bool get_addr_if_array) {
    this->state.get_val = get_val;
    this->state.get_addr_if_array = get_addr_if_array;
  }
  inline void set_state(bool get_val) {
    this->state.get_val = get_val;
  }
  
  // RO_ins 写一条寄存器-寄存器指令
  // op: 操作
  // r: 目标寄存器
  // s: 源寄存器
  // t: 源寄存器
  // 常用于ADD, MUL, SUB, JLT 等指令
  void RO_ins(const char *op, int r, int s, int t, const char *c);

  // RM_ins 写一条寄存器-内存指令
  // r - 寄存器
  // d - 偏移量(常数或寄存器号)
  // s - 基址寄存器
  // 常用于, LDA, LDC, ST, LD等指令
  void RM_ins(const char *op, int r, int d, int s,const char *c); 

  // RM_Abs_ins 将一个相对地址加上pc来转换成绝对地址
  // 并写一条寄存器-内存有关的指令
  void RM_Abs_ins(const char *op, int r, int a, const char *c);

  // skip 跳过n条指令
  // skip(0) 可以用于获取当前位置
  int skip(int n);
  
  // backup 存起当前位置
  void backup(int l);
  
  // restore恢复backup存的位置
  inline void restore() {
    eloc = highloc;
  }
  
  // 调用此函数来开始生成代码
  void gen_code();
};
}
#endif 
