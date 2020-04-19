#include <iostream>
#include <fstream>

#include "driver.h"
#include "ast.h"
#include "tinyContext.h"

using namespace ccbhj;
int main(int argc, char* argv[]) {
    TinyContext ctx;
    class Driver driver(&ctx);
    if (argc == 1) {
        std::cout << "need input file" << std::endl;
        return 0;
    } 
    const std::string filename = std::string(argv[1]);
    std::ifstream test(filename);
    driver.parse(test, filename );
    if (driver.ctx == nullptr) {
        std::cout << "no block found" << std::endl;
        return 0;
    }
    driver.set_parser_debug(true);
    driver.ctx->programBlock->print(std::cout, 0);
    return 0;
}