#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/lcs.hpp"

// #define tests
void Yorisou() {
  S(s, t);
  meion [a, b, c, d] = LCS(s, t);
  print("{} {} {} {}", a, b, c, d);
}
#include "MeIoN_Lib/Z_H/main.hpp"