#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  int n, m;
  while (IN(n, m)) [&]() {
    VEC(string, a, n);
    Z A = [&](int x, int y) -> bool {
      return x > 0 and y > 1 and a[x - 1][y - 2] == '^' and
          a[x - 1][y] == '^' and a[x][y - 1] == 'v';
    };
    Z B = [&](int x, int y) -> bool {
      return x > 0 and y > 1 and a[x - 1][y - 1] == '^' and
          a[x][y - 2] == 'v' and a[x][y] == 'v';
    };
    int ans = 0;
    Z go = [&]() {
      FOR(i, n) {
        int dp[m][5]{};
        FOR(k, m) {
          if (k) FOR(t, 5) chmax(dp[k][t], dp[k - 1][t]);

          if (A(i, k) and k > 2) FOR(t, 5) chmax(dp[k][0], dp[k - 3][t] + 1);
          if (A(i, k) and A(i, k - 1)) chmax(dp[k][2], dp[k - 1][0] + 1);
          if (A(i, k)) for (int t : {1, 3}) chmax(dp[k][0], dp[k - 2][t] + 1);

          if (B(i, k) and k > 2) FOR(t, 5) chmax(dp[k][1], dp[k - 3][t] + 1);
          if (B(i, k) and B(i, k - 1)) chmax(dp[k][3], dp[k - 1][1] + 1);
          if (B(i, k)) for (int t : {0, 2}) chmax(dp[k][1], dp[k - 2][t] + 1);

          if (A(i, k) and B(i, k))
            FOR(t, 5) chmax(dp[k][4], (k > 2 ? dp[k - 3][t] : 0) + 2);
        }
        int ad = 0;
        FOR(t, 5) chmax(ad, dp[m - 1][t]);
        ans += ad;
      }
      vector na(m, string(n, ' '));
      FOR(i, n) FOR(k, m) {
        na[k][i] = a[i][k];
      }
      swap(n, m);
      a.swap(na);
      FOR(i, n) FOR(k, m) {
        if (a[i][k] == '<') a[i][k] = '^';
        else if (a[i][k] == '>') a[i][k] = 'v';
        else a[i][k] = ' ';
      }
    };
    go(), go();
    UL(ans);
  }();
}
#include "YRS/Z_H/main.hpp"