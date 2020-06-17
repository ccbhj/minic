#include "code_gen_ctx.h"
#include "ast.h"
#include "context.h"
#include <cstdio>

using namespace ccbhj;


void CodeGenContext::RO_ins(const char *op, int r, int s, int t, const char *msg) {
  char buf[LINE_SIZE];
  std::snprintf(buf, LINE_SIZE,  "%3d: %5s %d,%d,%d", eloc++, op, r, s, t);
  print_buf(buf, msg);
  if (highloc < eloc) 
    highloc = eloc;
}

void CodeGenContext::RM_ins(const char *op, int r, int d, int s, const char *msg){
  char buf[LINE_SIZE];
  std::snprintf(buf, LINE_SIZE, "%3d: %5s %d,%d(%d)", eloc++, op, r, d, s);
  print_buf(buf, msg);
  if (highloc < eloc) 
    highloc = eloc;
}

int CodeGenContext::skip(int offset) {
  int i = eloc;
  eloc += offset;
  if (highloc < eloc)
    highloc = eloc;
  return i;
}

void CodeGenContext::backup(int l) {
  if (l > highloc) {
    print_err("BUG in backup");
  }
  eloc = l;
}

void CodeGenContext::RM_Abs_ins(const char *op, int r, int a, const char *msg) {
  char buf[LINE_SIZE];
  std::snprintf(buf, LINE_SIZE, "%3d: %5s %d,%d(%d)", eloc, op, r, a-(eloc+1), pc);
  eloc++;
  print_buf(buf, msg);
  if (highloc < eloc)
    highloc = eloc;
}

void CodeGenContext::gen_code() {
  FuncEntry func;
  ast_ctx->func_table.emplace(std::make_pair("input", func));
  ast_ctx->func_table.emplace(std::make_pair("output", func));

  // initialization
  print_debug("standard initialization");
  RM_ins("LD", gp, 0, ac, "load gp with max address");
  RM_ins("LDA", mp, 0, gp, "copy mp to fp");
  RM_ins("ST", ac, 0, ac, "clear location 0");
  this->tmp_offset = -2;
  print_debug("end initialization");
  // ast_ctx->new_func_scope(); // main scope
  
  int loc = skip(7);
  
  for (StmtNode *p : ast_ctx->programBlock->statements) {
    p->gen_code(*this, *this->ast_ctx);
  }
  
  auto it = ast_ctx->func_table.find("main");
  if (it == ast_ctx->func_table.end() || it->second.params.size() == 1) {
    print_err("can't find main(void) function");
  }
  
  backup(loc);
  int goffset = 0;
  for (auto it = ast_ctx->global_var_table.begin();
      it != ast_ctx->global_var_table.end();
      it++)
    goffset -= it->second.length;
  RM_ins("LDA", mp, goffset, gp, "grow stack for global variable");
  RM_ins("LDA", fp, 0, mp, "copy mp to fp");
  RM_ins("LDA", mp, -2, mp, "grow stack");
  RM_ins("LDA", ac, 1, pc, "save return point");
  int main_loc = it->second.meta_data.offset;
  RM_ins("LDC", pc, main_loc, 0, "go to main");

  RO_ins("HALT", 0, 0, 0, "");
}
