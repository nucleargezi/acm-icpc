#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/convolution.hpp"

// #define tests
using mint = M17;
using poly = vector<mint>;
void Yorisou() {
  LL(n, m);
  VEC(mint, a, n);
  VEC(mint, b, m);
  UL(convolution(a, b));
}
#include "MeIoN_Lib/Z_H/main.hpp"