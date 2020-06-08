#ifndef TINYCTX_H_
#define TINYCTX_H_

#include <map>
#include <string>
#include <vector>
#include <ostream>
#include "ast.h"

namespace ccbhj {
class Context {
public:
    BlockNode* programBlock = nullptr;
    ~Context() {
      if ( programBlock ) {
        delete programBlock;
      }
    }

    void print(std::ostream& os) {
      if (!programBlock)
        return;
      for (StmtNode* s: programBlock->statements) {
        s->print(os, 0);
      }
    }
};
}
#endif // ! TINYCTX_H_
