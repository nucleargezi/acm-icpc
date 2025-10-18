#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/multi_point.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, q);
  VEC(mint, f, n + 1);
  VEC(mint, x, q);
  for (meion v : multipoint_eval(f, x)) {
    UL(v.val);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"