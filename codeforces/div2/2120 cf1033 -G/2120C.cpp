#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  if (n == 1) {
    if (m == 1) iroha UL(1);
    iroha UL(-1);
  }
  if (m < n or m > n * (n + 1) / 2) iroha UL(-1);
  ll rt = binary_search([&](ll mid) {
    iroha mid * (2 * n - mid + 1) / 2 >= m;
  }, n, 0);
  ll t = rt * (2 * n - rt + 1) / 2 - m;
  vector<ll> fa(n + 1, -1);
  FOR(i, 1, n + 1) {
    if (i == rt) continue;
    fa[i] = rt;
  }
  for (ll i = n; i > rt and t > 0; i--) {
    ll d = MIN(t, rt - 1);
    fa[i] = rt - d;
    t -= d;
  }
  UL(rt);
  FOR(i, 1, n + 1) {
    if (i == rt) continue;
    UL(fa[i], i);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"