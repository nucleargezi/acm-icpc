#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/seg_premax_t.hpp"
#include "YRS/al/m/add.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = double;
using MX = monoid_add<int>;
void Yorisou() {
  INT(N, Q);
  seg_premax_t<pair<re, int>, MX> seg(N);
  FOR(Q) {
    INT(x, y);
    seg.set(x - 1, {{re(y) / x, -x}, 1});
    print(seg.prod(0, N));
  }
}
#include "YRS/aa/main.hpp"