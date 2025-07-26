#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/convolution.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, m);
  VEC(mint, a, n + 1);
  VEC(mint, b, m + 1);
  print("{}", convolution(a, b));
}
#include "MeIoN_Lib/Z_H/main.hpp"