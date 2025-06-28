#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"

#define tests
void Yorisou() {
  LL(n, k);
  VEC(ll, a, n);
  sort(a);
  ll sa = SUM(a);
  vector c = pre_sum(a);
  ll L = binary_search([&](ll m) -> bool {
    ll I1 = lower_bound(a, m), I2 = lower_bound(a, m + k);
    ll s = I1 * m;
    if (I2 > I1) s += c[I2] - c[I1];
    iroha s + (n - I2) * (m + k) >= sa;
  }, sa + k, -k);
  vector<ll> b(a);
  FOR(i, n) {
    chmax(b[i], L);
    chmin(b[i], L + k);
  }
  ll t = SUM(b) - sa;
  for (ll i = n - 1; i >= 0 and t > 0; --i) {
    ll rg = a[i];
    chmax(rg, L - 1);
    chmin(rg, L - 1 + k);
    ll d = MIN(t, b[i] - rg);
    b[i] -= d, t -= d;
  }
  ll ans = 0;
  FOR(i, n) {
    ans += b[i] * (b[i] + 1) / 2;
    ans += MAX(0ll, a[i] - b[i]) * k;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"