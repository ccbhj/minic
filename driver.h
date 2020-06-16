#ifndef DRIVER_H
#define DRIVER_H

#include <cassert>
#include <string>
#include <iostream>
#include "scanner.h"
#include "parser.hh"
#include "context.h"
#include "code_gen_ctx.h"


namespace ccbhj {
class Driver {
public:
    Context *ctx ;
    CodeGenContext code_gen_ctx;
    Scanner *scanner = nullptr;
    Parser *parser = nullptr;

    // whether to generate parse debug trace info;
    bool trace_parsing;
    // whether to generate scanner debug trace.
    bool trace_scanning;

    // ouput file name
    std::string output;
    // error output stream
    std::ostream *errout;
    // print the tree
    bool ptree = false;

public:
    Driver(): ctx(new Context()), code_gen_ctx(ctx), trace_parsing(false), trace_scanning(false),
    errout(&std::cerr) {}

    ~Driver() {
      if (scanner)
        delete scanner;
      scanner = nullptr;
      if (parser)
        delete parser;
      parser = nullptr;
    }
    
    // calling the parse on file.
    bool parse(std::istream &is, const std::string &stream_name); 
    // print error
    void error(const class location& l, const std::string& info);

    void set_ptree(bool p) {
      ptree = p;
    }
    void print_tree() {
      if (ptree)
        ctx->programBlock->print(std::cout, 0);
    }
    void gen_code() {
      code_gen_ctx.gen_code();
    }

    void set_error_output(std::ostream &os) {
      this->errout = &os;
    }

    void set_parser_debug(bool enable) {
      trace_parsing = enable;
    }

    void set_scanner_debug(bool enable) {
      trace_scanning = enable;
    }
};
}
#endif // !DRIVER_H
