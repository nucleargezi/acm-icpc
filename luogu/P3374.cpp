#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint_t.hpp"
// #include "YRS/mod/binom.hpp"
#include "YRS/ds/seg/range_sum_point_add.hpp"
#include "YRS/al/m/add.hpp"

using DS = range_sum_point_add<monoid_add<ll>, 1 << 4>;
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  DS seg(a);
  FOR(Q) {
    INT(op, x, y);
    if (op == 1) {
      --x;
      seg.multiply(x, y);
    } else {
      --x;
      print(seg.prod(x, y));
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"