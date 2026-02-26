#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/aa/def.hpp"
#include "YRS/ds/lct/lct.hpp"
#include "YRS/al/m/affine.hpp"

using mint = M99;
using MX = monoid_affine<mint>;
using DS = lct_mono_t<monoid_affine<mint>>;
void Yorisou() {
  INT(N, Q);
  DS ds(N);
  FOR(i, N) {
    INT(a, b);
    ds.set(i, MX::X{a, b});
  }
  FOR(N - 1) {
    INT(x, y);
    ds.link(x, y);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(a, b, c, d);
      ds.cut(a, b);
      ds.link(c, d);
    } else if (op == 1) {
      INT(p, a, b);
      ds.set(p, MX::X{a, b});
    } else {
      INT(x, y, t);
      print(ds.prod(x, y).eval(t));
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"