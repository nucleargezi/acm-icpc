#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, k);
  bool a[n][m]{};
  ll ans = inf<ll>;
  FOR(t, k) {
    LL(x, y);
    a[--x][--y] = 1;
    FOR(i, MAX(x - 1, 0ll), x + 1) {
      FOR(k, MAX(y - 1, 0ll), y + 1) {
        ll s = 0;
        FOR(x, i, MIN(i + 2, n)) {
          FOR(y, k, MIN(k + 2, m)) {
            s += a[x][y];
          }
        }
        if (s == 4) chmin(ans, t + 1);
      }
    }
  }
  UL(ans == inf<ll> ? 0 : ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"