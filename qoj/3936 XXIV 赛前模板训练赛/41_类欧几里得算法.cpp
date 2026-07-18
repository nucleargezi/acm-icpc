#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/floor_sum.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M11;
void Yorisou() {
  LL(N, a, b, c, k1, k2);
  ++N;
  Z ans = floor_sum_of_linear_poly_nonnegative<mint, 10, 10, ull>(N, a, b, c);
  print(ans[k1][k2]);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}