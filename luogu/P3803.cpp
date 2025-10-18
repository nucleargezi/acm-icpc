#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/convolution.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, m);
  VEC(mint, a, n + 1);
  VEC(mint, b, m + 1);
  UL(convolution(a, b));
}
#include "MeIoN_Lib/Z_H/main.hpp"