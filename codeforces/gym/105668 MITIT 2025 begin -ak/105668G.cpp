#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  const int N = n * m;
  VEC(int, a, N);
  vector<int> dp(N);
  static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  for (int i : argsort(a)) {
    int x = i / m, y = i % m;
    FOR(d, 4) {
      int xx = x + dx[d], yy = y + dy[d];
      if (not(xx > -1 and xx < n and yy > -1 and yy < m)) continue;
      int t = xx * m + yy;
      if (a[t] < a[i]) {
        chmax(dp[i], dp[t] + 1);
      }
    }
  }
  Yes(SUM(a) - SUM(dp) & 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"