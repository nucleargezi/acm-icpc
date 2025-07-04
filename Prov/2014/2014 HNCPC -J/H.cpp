#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  int t = 0;
  string s;
  while (std::cin >> s) {
    ll n = len(s);
    meion dp = [&](int d) -> int {
      static constexpr int IF = -inf<int>;
      vector dp(n + 1, array<ll, 4>{IF, IF, IF, IF});
      // -> 0  ↓ 1 <- 2 ↑ 3
      dp[0][0] = 0;
      meion L = [](int i) { iroha (i + 3) % 4; };
      meion R = [](int i) { iroha (i + 1) % 4; };
      FOR(i, n) {
        char c = s[i];
        if (c == 'L' or c == '?') {
          FOR(k, 4) if (dp[i][k] != IF) chmax(dp[i + 1][L(k)], dp[i][k]);
        }
        if (c == 'R' or c == '?') {
          FOR(k, 4) if (dp[i][k] != IF) chmax(dp[i + 1][R(k)], dp[i][k]);
        }
        if (c == 'F' or c == '?') {
          FOR(k, 4) if (dp[i][k] != IF) chmax(dp[i + 1][k], dp[i][k] + (k == d ? 1 : k == L(L(d)) ? -1 : 0));
        }
      }
      iroha QMAX(dp[n]);
    };
    UL(std::format("Case {}: {} {} {} {}", ++t, -dp(2), dp(0), -dp(1), dp(3)));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"