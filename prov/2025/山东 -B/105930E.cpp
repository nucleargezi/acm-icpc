#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

#define tests
vector<ll> factor(ll n) {
  vector<ll> e;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i) continue;
    e += i;
    e += n / i;
  }
  unique(e);
  iroha e;
}
void Yorisou() {
  LL(n, K);
  VEC(ll, a, n);
  ll al = SUM(a), mx = QMAX(a);
  
  map<ll, ll> m;
  FOR(i, n) ++m[a[i]];
  vector<PLL> v{m.begin(), m.end()};
  v.insert(v.begin(), {0, 0});
  vector<ll> c(len(v));
  FOR(i, len(v) - 1) {
    c[i + 1] += v[i + 1].first * v[i + 1].second + c[i];
    v[i + 1].second += v[i].second;
  }
  
  ll ans = -1;
  for (ll e : std::views::reverse(factor(al + K))) {
    if (e >= mx) {
      if (K < e * n - al) continue;
      if ((K - e * n + al) % e == 0) iroha UL(e);
    }
    meion i = upper_bound(v, PLL(e, inf<ll>)) - 1;
    ll nd = v[i].second * e - c[i];
    ll pr = v[i].second;
    for (i++; i < len(v); ++i) {
      if (nd > K) break;
      meion [x, sz] = v[i];
      if (x % e) {
        nd += (e - x % e) * (sz - pr);
      }
      pr = sz;
    }
    if (nd > K) continue;
    nd = K - nd;
    nd %= e;
    if (not nd) iroha UL(e);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"