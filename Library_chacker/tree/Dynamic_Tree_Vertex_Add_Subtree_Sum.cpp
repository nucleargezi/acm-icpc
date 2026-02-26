#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/lct/lct.hpp"
#include "YRS/al/m/add.hpp"

using DS = lct_sub_t<monoid_add<ll>>;
void Yorisou() {
  INT(N, Q);
  DS ds(N);
  FOR(i, N) IN(ds.a[i].mx);
  FOR(N - 1) {
    INT(x, y);
    ds.link(x, y);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y, a, b);
      ds.cut(x, y);
      ds.link(a, b);
    } else if (op == 1) {
      INT(p, x);
      ds.multiply(p, x);
    } else {
      INT(x, f);
      print(ds.prod(x, f));
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"