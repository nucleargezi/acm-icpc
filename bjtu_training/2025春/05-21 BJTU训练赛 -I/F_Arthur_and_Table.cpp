#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, l, n);
  VEC(ll, c, n);
  ll N = QMAX(l) + 1;
  vector<vector<ll>> v(N);
  FOR(i, n) v[l[i]] += c[i];
  FOR(i, N) sort(v[i]);
  ll ans = inf<ll>;
  ll X = SUM(c), Y = 0;
  multiset<ll> se;
  FOR(i, N) {
    for (int x : v[i]) X -= x;
    if (not v[i].empty()) {
      ll c = 0;
      for (int t = len(v[i]) - 1; ll x : se) {
        if (not t) break;
        c += x, --t;
      }
      chmin(ans, c + X + Y);
    }
    for (int x : v[i]) Y += x, se += -x;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"