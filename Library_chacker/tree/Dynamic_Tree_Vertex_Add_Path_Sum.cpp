#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/al/m/add.hpp"
// #include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/ds/lct/lct.hpp"

using DS = lct_mono_t<monoid_add<ll>>;
void Yorisou() {
  INT(N, q);
  DS ds(N);
  FOR(i, N) {
    INT(x);
    ds[i]->mx = x;
  }
  FOR(N - 1) {
    INT(x, y);
    ds.link(x, y);
  }
  FOR(q) {
    INT(op);
    if (op == 0) {
      INT(a, b, c, d);
      ds.cut(a, b);
      ds.link(c, d);
    } else if (op == 1) {
      INT(p, x);
      ds.set(p, ds.prod(p, p) + x);
    } else {
      INT(x, y);
      print(ds.prod(x, y));
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"