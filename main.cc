#include <iostream>
#include <fstream>

#include "driver.h"

using namespace ccbhj;

enum {
  PTREE = 1 ,
  DPARSER = 2,
  DSCANNER = 3,
  DCODE_GEN = 4,
  PSYMTAB = 5,
  FLAG_COUNT = 5,
};

void print_usage() {
  using std::cout;
  using std::endl;
  std::cout << "Usage: " << endl;
  std::cout << "  minic [options] input output" << endl;
  std::cout << "  options: " << endl;
  std::cout << "       -p  print parser debug info" << endl;
  std::cout << "       -s  print scanner debug info" << endl;
  std::cout << "       -t  print tree" << endl;
  std::cout << "       -d  debug code generation info" << endl;
  std::cout << "       -x  print symtab" << endl;
  std::cout << "       -h  print help info and exit" << endl;
}

int parse_args(int argc, char** argv) {
  int j = 1;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-')
      continue;
    switch(argv[i][1]) {
      case 'p': j |= (1 << int(DPARSER)); break;
      case 's': j |= (1 << DSCANNER); break;
      case 'x': j |= (1 << PSYMTAB); break;
      case 't': j |= (1 << PTREE); break;
      case 'd': j |= (1 << DCODE_GEN); break;
      case 'h': print_usage(); return -1;
      default:
                std::cout << "invalid options " << argv[i] << std::endl;
                return -2;
    }
  }
  return j;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "need more argument" << std::endl;
    return 0;
  } 
  Driver driver;
  int parse = parse_args(argc, argv);
  if (parse < 0) 
    return 0;
  bool ptree = false;
  for (int i = 1; i < FLAG_COUNT + 1; i++) {
    int t = parse & (1 << i);
    if (!t)
      continue;
    switch(i) {
      case PTREE: ptree = true; continue;
      case DPARSER: driver.set_parser_debug(true); continue;
      case DSCANNER: driver.set_scanner_debug(true); continue;
      case DCODE_GEN: driver.code_gen_ctx.set_debug(true); continue;
      case PSYMTAB: driver.ctx->set_debug(true); continue;
    } 
  }
  const std::string filename = std::string(argv[argc - 2]);
  std::ifstream file(filename);
  if (driver.parse(file, filename))  {
    file.close();
  } else {
    return 0;
  }
  if (ptree) 
    driver.ctx->programBlock->print(std::cout, 0);
  std::string os(argv[argc - 1]);
  driver.code_gen_ctx.set_out(os);
  driver.gen_code();
  return 0;
}
