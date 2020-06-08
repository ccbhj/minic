#ifndef _CODE_GEN_CTX_H
#define _CODE_GEN_CTX_H

#include "parser.hh"
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support//TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
// #include <llvm/ExecutionEngine/JIT.h>
#include <llvm/Support/raw_ostream.h>
#include <map>
#include <stack>

static llvm::LLVMContext llvmctx;

namespace ccbhj {
class CodeGenBlock {
  public:
    llvm::BasicBlock *block;
    llvm::Value *return_val;
    std::map<std::string, llvm::Value*> locals;
};

class CodeGenContext{
  private:
    std::stack<CodeGenBlock*> blocks;
    llvm::Function *main_func;

  public:
    llvm::Module *mod;
    CodeGenContext(): mod(new llvm::Module("main", llvmctx)) {}

    void generate_code(BlockNode *root);
    llvm::GenericValue runCode();
    std::map<std::string, llvm::Value*>& locals() {
      return blocks.top()->locals;
    }

    llvm::BasicBlock* current_block() {
      return blocks.top()->block;
    }

    void push_block(llvm::BasicBlock *block) {
      blocks.push(new CodeGenBlock());
      blocks.top()->return_val = NULL;
      blocks.top()->block = block;
    }

    void pop_block() {
      CodeGenBlock *top = blocks.top();
      blocks.pop();
      delete top;
    }

    void set_current_ret_val(llvm::Value *val) {
      blocks.top()->return_val = val;
    }

    llvm::Value* get_current_ret_val() {
      return blocks.top()->return_val;
    }
};

}

#endif
