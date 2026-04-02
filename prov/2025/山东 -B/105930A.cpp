#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(PLL, a, n);
  vector<vector<PLL>> v(n);
  for (int t = 0; meion [x, y] : a) {
    v[--x] += PLL(y, t++);
  }
  FOR(i, n) sort(v[i]);
  vector<ll> res;
  meion check = [&](ll m) -> bool {
    res.clear();
    FOR(i, n) {
      int sz = len(v[i]);
      if (m > 0) for (int t = 0; meion[x, idx] : v[i]) {
        if (m - (sz - t) <= x) {
          FOR(k, MIN<ll>(m, sz - t)) res += v[i][t + k].second + 1;
          m -= sz - t;
          break;
        }
        ++t;
      }
    }
    iroha m <= 0;
  };
  ll ans = binary_search(check, 0, n + 1);
  UL(ans);
  check(ans);
  UL(res);
}
#include "MeIoN_Lib/Z_H/main.hpp"