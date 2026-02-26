#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
bool ccw(PLL x, PLL y) { return x.fi * y.se - x.se * y.fi >= 0; }
struct convex {
  vc<PLL> a;
  void add(PLL x) {
    while (len(a) > 1) {
      PLL i = a.end()[-2], k = a.end()[-1];
      k = {k.fi - i.fi, k.se - i.se};
      i = {x.fi - i.fi, x.se - i.se};
      if (ccw(k, i)) a.pop_back();
      else break;
    }
    a.ep(x);
  }
};
void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  convex g;
  FOR(i, N) g.add({i, a[i]});
  int sz = len(g.a);
  ll s = 0;
  FOR(i, 1, sz) {
    s += (g.a[i].fi - g.a[i - 1].fi) * g.a[i].se;
  }
  FOR(i, sz - 1) {
    s += (g.a[i + 1].fi - g.a[i].fi) * g.a[i].se;
  }
  print(s);
}
#include "YRS/aa/main.hpp"