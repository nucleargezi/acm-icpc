#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/al/m/add.hpp"
#include "YRS/ds/seg/range_sum_point_add.hpp"
#include "YRS/poly/line_inte.hpp"

using mint = M17;
using DS = range_sum_point_add<monoid_add<mint>>;
fps_t<mint> X;
void Yorisou() {
  LL(N, K);
  --K;
  VEC(mint, a, N);
  sh(a, N + N + 2);
  DS seg(a);
  FOR(i, N, N + N + 2) seg.multiply(i, seg.prod(i - N, i));
  a = seg.get_all();
  print(X.line_inte(a, K), X.line_inte(pre_sum<0>(a), K));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"