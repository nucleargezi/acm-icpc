#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/seg/range_min_add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  range_min_add<ll> seg(a);
  FOR(Q) {
    INT(op, l, r);
    if (op == 0) {
      INT(x);
      seg.apply(l, r, x);
    } else {
      print(seg.prod(l, r));
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"