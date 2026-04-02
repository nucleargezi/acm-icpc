#include "YRS/all.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/poly/subset_sum.hpp"
#include "YRS/poly/prod_of_one_minus_xn.hpp"

using mint = M11;
fps_t<mint> X;
void Yorisou() {
  INT(N, S, K);
  S -= 1ll * K * N * (N - 1) / 2;
  if (S < 0) return print(0);
  vc<int> a(N);
  iota(all(a), 1);
  print(X.prod_of_inv_one_minus_xn(a, S)[S]);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"