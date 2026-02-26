#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/seg/segd_sprase_t.hpp"
#include "YRS/al/m/add.hpp"
#include "YRS/ds/basic/unordered_discreate.hpp"

using ds = segd_sprase_t<monoid_add<int>, 0>;
using np = ds::np;
void Yorisou() {
  INT(N, Q);
  unordered_discreate dis(N + Q);
  VEC(int, a, N);
  a = dis.build(a);
  vc<np> t(N + Q);
  ds seg(0, N);
  FOR(i, N) {
    int x = a[i];
    t[x] = seg.multiply(t[x], i, 1);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y);
      int p = a[x];
      t[p] = seg.multiply(t[p], x, -1);
      p = a[x] = dis.add(y);
      t[p] = seg.multiply(t[p], x, 1);
    } else {
      INT(l, r, x);
      x = dis.get(x, -1);
      if (x == -1) print(0);
      else print(seg.prod(t[x], l, r));
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"