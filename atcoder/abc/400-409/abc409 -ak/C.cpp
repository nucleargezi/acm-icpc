#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, L);
  VEC(ll, d, n - 1);
  d = pre_sum(d);
  FOR(i, n) d[i] %= L;
  sort(d);
  map<ll, ll> m;
  FOR(i, n) ++m[d[i]];
  ll ans = 0;
  if (L % 3 == 0)
  for (meion [x, y] : m) {
    if (m.contains(x + L / 3) and m.contains(x + L / 3 * 2)) {
      ans += y * m[x + L / 3] * m[x + L / 3 * 2];
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"