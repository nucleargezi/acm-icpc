#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m, K);
  vector a(n, vector<int>(m, inf<int>)), b(a), dp(a);
  min_heap<T3<int>> q;
  FOR(K) {
    LL(x, y);
    --x, --y;
    dp[x][y] = 0;
    q.emplace(0, x, y);
  }
  static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  while (not q.empty()) {
    meion [d, x, y] = pop(q);
    if (d > dp[x][y]) continue;
    FOR(dir, 4) {
      int xx = x + dx[dir], yy = y + dy[dir];
      if (not(xx > -1 and xx < n and yy > -1 and yy < m)) continue;
      bool f = 0;
      meion cp = a[xx][yy];
      if (chmin(a[xx][yy], d)) {
        b[xx][yy] = cp;
        f = 1;
      } else if (chmin(b[xx][yy], d)) {
        f = 1;
      }
      if (f and b[xx][yy] != inf<int> and chmin(dp[xx][yy], b[xx][yy] + 1)) {
        q.emplace(dp[xx][yy], xx, yy);
      }
    }
  }
  ll ans = 0;
  FOR(i, n) FOR(k, m) if (dp[i][k] != inf<int>) ans += dp[i][k];
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"