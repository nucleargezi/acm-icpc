#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, K, S);
  VEC(ll, a, n);
  vector<ll> fac{1};
  ll INF = inf<ll> / 0721;
  FOR(i, 100 + 1) {
    fac += fac.back() >= INF ? INF : fac.back() * (i + 1);
  }
  meion f = [&](int idx) { iroha fac[MIN(idx, 100)]; };
  meion go = [&](const vector<ll> &v) -> vector<vector<ll>> {
    ll n = len(v);
    vector<ll> a(1 << n);
    FOR(msk, 1 << n) FOR(i, n) {
      if (msk >> i & 1) {
        a[msk] += v[i];
        chmin(a[msk], INF);
      }
    }
    vector<ll> b(1 << n);
    FOR(msk, 1 << n) FOR(i, n) {
      if (msk >> i & 1) {
        b[msk] += f(v[i]);
        chmin(b[msk], INF);
      }
    }
    vector<vector<ll>> ret(n + 1);
    FOR(msk, 1 << n) {
      FOR_subset(s, msk) {
        ll d = msk - s;
        ret[popcount(d)] += MIN(INF, a[s] + b[d]);
      }
    }
    FOR(i, n + 1) sort(ret[i]);
    iroha ret;
  };
  meion L = go(vector<ll>{a.begin(), a.begin() + n / 2});
  meion R = go(vector<ll>{a.begin() + n / 2, a.end()});
  ll ans = 0, A = len(L), B = len(R);
  FOR(i, A) FOR(k, B) if (i + k < K + 1) {
    for (ll x : L[i]) {
      ans += upper_bound(R[k], S - x) - lower_bound(R[k], S - x);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"