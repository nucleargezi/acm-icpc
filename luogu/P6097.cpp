#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/set/subset_convolution.hpp"

// #define tests
using mint = modint<1'000'000'000 + 9>;
void Yorisou() {
  INT(n);
  const int N = 1 << n;
  VEC(mint, a, N);
  VEC(mint, b, N);
  UL(subset_convolution(a, b));
}
#include "MeIoN_Lib/Z_H/main.hpp"