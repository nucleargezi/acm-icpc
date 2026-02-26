#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/tr/ddp.hpp"

#define tests 0
#define fl 0
#define DB 10
struct DP {
  struct X {
    int umax, umin;
    int dmax, dmin;
    int c, dis, mx, mn;
    ll us, ds, s;
  };
  static X com(X L, X R) {
    X res;
    res.umax = max(L.umax, L.dis + R.umax);
    res.umin = min(L.umin, L.dis + R.umin);
    res.us = L.us + 1ll * L.dis * R.c + R.us;

    res.dmax = max(R.dmax, R.dis + L.dmax);
    res.dmin = min(R.dmin, R.dis + L.dmin);
    res.ds = R.ds + 1ll * R.dis * L.c + L.ds;

    res.c = L.c + R.c;
    res.dis = L.dis + R.dis;
    res.mx = max({L.mx, R.mx, L.dmax + R.umax});
    res.mn = min({L.mn, R.mn, L.dmin + R.umin});
    res.s = L.s + R.s + L.ds * R.c + R.us * L.c;
    return res;
  }
  static X rak(X L, X R) {
    X res;
    res.umax = max(L.umax, R.umax);
    res.umin = min(L.umin, R.umin);
    res.us = L.us + R.us;

    res.dmax = max(L.dmax, R.umax + L.dis);
    res.dmin = min(L.dmin, R.umin + L.dis);
    res.ds = L.ds + 1ll * L.dis * R.c + R.us;

    res.c = L.c + R.c;
    res.dis = L.dis;
    res.mx = max({L.mx, R.mx, L.umax + R.umax});
    res.mn = min({L.mn, R.mn, L.umin + R.umin});
    res.s = L.s + R.s + L.us * R.c + R.us * L.c;
    return res;
  }
};
using X = DP::X;
void Yorisou() {
  INT(N);
  graph g(N);
  g.sc();
  hld v(g);

  static constexpr int in = inf<int> / 2;
  Z sn = [&](int) -> X { return {1, 1, 0, 0, 1, 1, -in, in, 1, 0, 0}; };
  Z se = [&](int) -> X { return {-in, in, -in, in, 0, 1, -in, in, 0, 0, 0}; };
  ddp_t<int, DP> dp(v, se);
  
  INT(Q);
  vc<int> a;
  FOR(Q) {
    INT(sz);
    a.resize(sz);
    IN(a);
    for (int x : a) dp.set(x - 1, sn(1));
    X s = dp.prod();
    print(s.s, s.mn, s.mx);
    for (int x : a) dp.set(x - 1, se(1));
  }
}
#include "YRS/aa/main.hpp"