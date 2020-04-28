#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>
#include "scanner.h"
#include "parser.hh"
#include "context.h"


namespace ccbhj {
class Driver {
public:
    Driver(Context* ctx)
        : ctx(ctx), trace_parsing(false), trace_scanning(false) {}
    virtual ~Driver();
    
    // stream name;
    std::string output;

    Context* ctx = nullptr;
    
    // whether to generate parse debug trace info;
    bool trace_parsing;
    // whether to generate scanner debug trace.
    bool trace_scanning;

    Scanner* scanner = nullptr;
    Parser* parser = nullptr;
    // calling the parse on file f.
    int parse(std::istream &is, const std::string &stream_name); 
    // print error
    void error(const class location& l, const std::string& info);

    void set_parser_debug(bool enable) {
      trace_parsing = enable;
    }

    void set_scanner_debug(bool enable) {
      trace_scanning = enable;
    }
};
}
#endif // !DRIVER_H
