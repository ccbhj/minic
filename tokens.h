#ifndef TOKEN_H_
#define TOKEN_H_

namespace ccbhj {
// 一元符号
enum class UaOpt {
  neg, // -
};

enum class BiOpt {
  plus = 1, // +
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

} // namespace ccbhj
#endif
