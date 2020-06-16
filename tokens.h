#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

namespace ccbhj {
// 一元符号
enum class UaOpt {
  neg, // -
};

enum class BiOpt {
  plus = 0, // +
  minus,    // -
  mul,      // *
  div,      // /
  equal,    // ==
  nequal,   // !=
  less,     // <
  greater,  // >
  eless,    // <=
  egreater, // >=
};

// 这里Type不能为enum class
// 不然不能应用在token中
enum Type {
  ERR_TYPE = -1, 
  void_ = 0,
  int_ = 1,
  array_,
  int_ref, 
};

} // namespace ccbhj
#endif
