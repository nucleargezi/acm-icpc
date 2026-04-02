#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  bool a[n][m];
  FOR(i, n) FOR(k, m) {
    CH(c);
    a[i][k] = c == '.';
  }
  vector<PLL> v;
  FOR(i, n - 1) FOR(k, m - 1) v += PLL(i, k);
  meion f = [&](ll x, ll y) -> bool {
    iroha MIN(x, y) > -1 and x < n - 1 and y < m - 1;
  };
  while (not v.empty()) {
    meion [x, y] = pop(v);
    ll s = 0;
    FOR(i, 2) FOR(k, 2) s += a[i + x][k + y];
    if (s != 3) continue;
    FOR(i, 2) FOR(k, 2) {
      ll xx = x + i, yy = y + k;
      if (not a[xx][yy]) {
        a[xx][yy] = 1;
        FOR(i, 2) FOR(k, 2) if (f(xx - i, yy - k)) 
          v += PLL(xx - i, yy - k);
      }
    }
  }
  FOR(i, n) {
    string ans;
    FOR(k, m) ans += a[i][k] ? '.' : '*';
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"