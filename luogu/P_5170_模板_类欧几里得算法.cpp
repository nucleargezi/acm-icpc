#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/floor_sum.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

#define tests
using mint = M99;
void Yorisou() {
  LL(n, a, b, c);
  ++n;
  meion ans = floor_sum_of_linear_poly_nonnegative<mint, 1, 2, ull>(n, a, b, c);
  UL(ans[0][1].val, ans[0][2].val, ans[1][1].val);
}
#include "MeIoN_Lib/Z_H/main.hpp"