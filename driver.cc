#include "driver.h"
#include <cctype>

namespace ccbhj {

bool Driver::parse(std::istream &is, const std::string &stream_name) {
  if (!is.good()) {
    exit(EXIT_FAILURE);
  }
  output = stream_name;
  this->scanner = new Scanner(&is);
  scanner->set_debug(trace_scanning);

  this->parser = new Parser(*this);
  parser->set_debug_level(trace_parsing);

  return parser->parse() == 0;
}

void Driver::error(const class location &l, const std::string &info) {
  *errout << l << ": " << info << std::endl;
}
} // namespace ccbhj
