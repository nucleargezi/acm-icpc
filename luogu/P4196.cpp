#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ge/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using RE = long double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  vc<convex_polygon<RE>> a;
  FOR(N) {
    INT(sz);
    VEC(P, e, sz);
    e = rearrange(e, hull(e));
    a.ep(e);
  }
  FOR(i, 1, N) {
    int sz = len(a[i]);
    FOR(k, sz) {
      int j = (k + 1) % sz;
      Z t = a[i - 1].convex_cut(a[i].ps[k], a[i].ps[j]);
      t = rearrange(t, hull(t));
      a[i - 1] = convex_polygon(t);
    }
    swap(a[i], a[i - 1]);
  }
  setp(3);
  print(a[N - 1].area() / 2.L);
}
#include "YRS/Z_H/main.hpp"