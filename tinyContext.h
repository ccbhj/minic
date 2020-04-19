#ifndef TINYCTX_H_
#define TINYCTX_H_

#include <map>
#include <string>
#include <vector>
#include "ast.h"

namespace ccbhj {
class TinyContext {
public:
    BlockNode* programBlock = nullptr;
    ~TinyContext() {
        delete programBlock;
    }
};
}
#endif // ! TINYCTX_H_
