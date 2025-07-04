#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  S(s, t);
  int n = len(s), m = len(t);
  int dp[n + 1][m + 1]{}, fa[n + 1][m + 1]{};
  FOR(i, n + 1) FOR(k, m + 1) {
    if (not i and k) {
      dp[i][k] = dp[i][k - 1] + 1;
      fa[i][k] = 1;
    } else if (i and not k) {
      dp[i][k] = dp[i - 1][k] + 1;
      fa[i][k] = 2;
    } else if (i and k) {
      dp[i][k] = dp[i - 1][k - 1] + (s[i - 1] != t[k - 1]);
      if (chmin(dp[i][k], dp[i][k - 1] + 1)) {
        fa[i][k] = 1;
      }
      if (chmin(dp[i][k], dp[i - 1][k] + 1)) {
        fa[i][k] = 2;
      }
    }
  }
  vector<int> os, ot, es, et;
  for (int i = n, k = m; i or k; ) {
    if (fa[i][k] == 0) {
      --i, --k;
      os += i, ot += k;
    } else if (fa[i][k] == 1) {
      --k;
      et += k;
    } else {
      --i;
      es += i;
    }
  }
  UL(dp[n][m]);
  for (int x : es) UL("DELETE", x + 1);
  for (int x : std::views::reverse(et)) UL("INSERT", x + 1, t[x]);
  FOR(i, len(os)) if (s[os[i]] != t[ot[i]]) {
    UL("REPLACE", ot[i] + 1, t[ot[i]]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"