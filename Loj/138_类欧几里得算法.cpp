#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/floor_sum.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

#define tests
using mint = M17;
void Yorisou() {
  LL(n, a, b, c, k1, k2);
  ++n;
  meion ans = floor_sum_of_linear_poly_nonnegative<mint, 10, 10, ull>(n, a, b, c);
  UL(ans[k1][k2]);
}
#include "MeIoN_Lib/Z_H/main.hpp"