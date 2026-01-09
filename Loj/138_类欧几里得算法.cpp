#include "YRS/all.hpp"
#include "YRS/pr/floor_sum.hpp"
#include "YRS/mod/modint.hpp"

void before() {}

#define tests
using mint = M17;
void Yorisou() {
  LL(n, a, b, c, k1, k2);
  ++n;
  Z ans = floor_sum_of_linear_poly_nonnegative<mint, 10, 10, ull>(n, a, b, c);
  print(ans[k1][k2]);
}