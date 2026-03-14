#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/set/subset_convolution.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  VEC(mint, a, 1 << n);
  VEC(mint, b, 1 << n);
  UL(subset_convolution(a, b));
}
#include "MeIoN_Lib/Z_H/main.hpp"