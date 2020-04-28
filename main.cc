#include <iostream>
#include <fstream>

#include "driver.h"
#include "ast.h"
#include "context.h"

using namespace ccbhj;
void print_usage() {
  using std::cout;
  using std::endl;
  std::cout << "Usage: " << endl;
  std::cout << "  minic [options] target file" << endl;
  std::cout << "  options: " << endl;
  std::cout << "       -p  print parser debug info" << endl;
  std::cout << "       -s  print scanner debug info" << endl;
  std::cout << "       -h  print help info" << endl;
}

void parse_args(int argc, char** argv, Driver &drv) {
  if (argc == 1)  {
    return;
  }
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-')
      continue;
    switch(argv[i][1]) {
      case 'p': drv.set_parser_debug(true); break;
      case 's': drv.set_scanner_debug(true); break;
      case 'h': print_usage(); break;
      default:
                std::cout << "invalid options " << argv[i] << std::endl;
    }
  }
}

int main(int argc, char* argv[]) {
    Context ctx;
    class Driver driver(&ctx);
    if (argc == 1) {
        std::cout << "need input file" << std::endl;
        return 0;
    } 
    parse_args(argc, argv, driver);
    const std::string filename = std::string(argv[argc - 1]);
    std::ifstream file(filename);
    driver.parse(file, filename );
    if (driver.ctx == nullptr) {
        std::cout << "no block found" << std::endl;
        return 0;
    }
    if (driver.ctx->programBlock)
      driver.ctx->programBlock->print(std::cout, 0);
    file.close();
    return 0;
}
