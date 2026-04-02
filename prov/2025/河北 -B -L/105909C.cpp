#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  using ll = i128;
  LL(n, m, K, x);
  ll sz = m / x;
  chmin(sz, n);
  vector<ll> b(n), c(n);
  FOR(i, n) IN(b[i], c[i]);
  if (x * n < m) iroha NO();
  vector<int> I(n);
  FOR(i, n) I[i] = i;
  sort(I, [&](int f, int t) -> bool {
    iroha((x - b[f]) * (K * x - c[f])) + b[f] * c[f] >
        ((x - b[t]) * (K * x - c[t])) + b[t] * c[t];
  });
  ll ans = 0;
  vector<ll> a(n);
  FOR(i, sz) a[i] = x;
  if (sz < n) a[sz] = m % x;
  ll A = 0, B = 0;
  FOR(i, n) {
    A += (ll)a[i] * (c[I[i]] + K * a[i]);
    B += (ll)b[I[i]] * (c[I[i]] + K * a[i]);
  }
  YES(A > B);
}
#include "MeIoN_Lib/Z_H/main.hpp"