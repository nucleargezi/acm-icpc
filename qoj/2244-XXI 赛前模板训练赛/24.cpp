#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/multi_point.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, q);
  VEC(mint, a, n);
  VEC(mint, x, q);
  for (meion y : multipoint_eval(a, x)) {
    print("{}", y);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"