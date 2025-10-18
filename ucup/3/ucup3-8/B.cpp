#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  int c = 0;
  vector<int> dp(N + 1, -1), ndp(dp);
  dp[0] = 0;
  FOR(N) {
    STR(op);
    if (op == "B") {
      ++c;
      ndp = dp;
      FOR(i, N) if (dp[i + 1] != -1) chmax(ndp[i], dp[i + 1] + 1);
    } else {
      INT(a, b);
      fill(all(ndp), -1);
      FOR(i, N) if (dp[i] != -1) chmax(ndp[i], dp[i] + std::min(a, c - dp[i]));
      FOR(i, N) if (dp[i] != -1) chmax(ndp[std::min(N, i + b)], dp[i]);
    }
    dp.swap(ndp);
  }
  print(c + QMAX(dp));
}
#include "YRS/Z_H/main.hpp"