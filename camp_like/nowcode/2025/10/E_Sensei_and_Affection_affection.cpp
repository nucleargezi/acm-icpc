#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

#define tests
void Yorisou() {
  INT(n, m);
  VEC(int, a, n);
  int mx = QMAX(a);
  a.emplace_back(mx);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += std::max(0, a[i + 1] - a[i]);
  }
  if (m == 1) iroha UL(ans);

  static constexpr int I = inf<int> / 4;
  static constexpr pair<int, int> INF = {I, I};
  for (int x = 0; x < 201; ++x) {
    for (int y = std::max(mx, x); y < 201; ++y) {
      pair<int, int> dp{0, 0}, ndp;
      a.back() = y;
      if (a[0] > x)
        dp.first = I;
      else
        dp.first = 0;
      for (int i = 1; i < n + 1; ++i) {
        ndp = INF;
        int k = a[i - 1];
        if (a[i] <= x) {
          chmin(ndp.first, dp.first + std::max(0, a[i] - k));
          chmin(ndp.first, dp.second + std::max(0, (y - k) - (x - a[i])));
        }
        chmin(ndp.second, dp.second + std::max(0, a[i] - k));
        chmin(ndp.second, dp.first + std::max(0, (x - k) - (y - a[i])));
        swap(dp, ndp);
      }
      meion [X, Y] = dp;
      chmin(ans, X);
      chmin(ans, Y);
    }
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"