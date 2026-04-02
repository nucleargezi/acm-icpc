#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/mod/powertable.hpp"

#define tests 1
#define fl 0
#define DB 10
constexpr ll sq(ll x) { return x * x; }
struct dat {
  ll w;
  int x, c;
  dat(ll w, int x, int c) : w(w), x(x), c(c) {}
  constexpr bool better(const dat &x) {
    if (w <= x.w and c <= x.c) return 1;
    return 0;
  }
  constexpr bool operator==(const dat &p) const {
    return w == p.w and x == p.x and c == p.c;
  }
  constexpr tuple<ll, int, int> totuple() const { return {w, x, c}; }
  constexpr bool operator<(const dat &p) const { return totuple() < p.totuple(); }
};
void Yorisou() {
  INT(N);
  vc<PII> a(N);
  FOR(i, N) cin >> a[i].fi;
  FOR(i, N) cin >> a[i].se;
  FOR(i, N) chmin(a[i].se, a[i].fi + 2);
  vc<dat> dp, ndp;
  FOR(i, a[0].fi, a[0].se + 1) dp.ep(0, i, 1);
  FOR(i, 1, N) {
    Z [l, r] = a[i];
    ndp.clear();
    for (const dat &x : dp) {
      FOR(i, l, r + 1) {
        if (i == x.x) ndp.ep(x.w, x.x, x.c + 1);
        else ndp.ep(x.w + sq(x.c), i, 1);
      }
    }
    unique(ndp);
    int sz = len(ndp);
    dp.clear();
    FOR(i, sz) {
      bool fail = 0;
      FOR(k, sz) if (i != k and ndp[i].x == ndp[k].x) {
        if (ndp[k].better(ndp[i])) {
          fail = 1;
          break;
        }
      }
      if (not fail) dp.ep(ndp[i]);
    }
  }
  ll ans = inf<ll>;
  for (Z [w, x, c] : dp) chmin(ans, w + sq(c));
  print(ans);
}
#include "YRS/aa/main.hpp"