#include "driver.h"
#include <cctype>

namespace ccbhj {
Driver::~Driver() {
  delete scanner;
  scanner = nullptr;
  delete parser;
  parser = nullptr;
}

int Driver::parse(std::istream &is, const std::string &stream_name) {
  if (!is.good()) {
    exit(EXIT_FAILURE);
  }
  output = stream_name;
  scanner = new Scanner(&is);
  scanner->set_debug(trace_scanning);

  parser = new Parser(*this);
  parser->set_debug_level(trace_parsing);
  return parser->parse() == 0;
}

void Driver::error(const class location &l, const std::string &info) {
  std::cerr << l << ": " << info << std::endl;
}
} // namespace ccbhj
