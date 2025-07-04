#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = double;
void Yorisou() {
  int t = 0;
  int n;
  vector<RE> pa(5), pb(5);
  while (std::cin >> pa >> pb) {
    RE dp[11][6][6]{}, T[6][6]{};
    dp[0][0][0] = 1;
    FOR(i, 11) FOR(a, 6) FOR(b, 6) {
      if (not dp[i][a][b]) continue;
      if (i == 10) {
        T[a][b] += dp[i][a][b];
        continue;
      }
      if (a > b + 5 - i + (i + 1) / 2 or b > a + 5 - (i + 1) / 2) {
        T[a][b] += dp[i][a][b];
        continue;
      }
      if (i & 1) {
        dp[i + 1][a][b + 1] += dp[i][a][b] * pb[i / 2];
        dp[i + 1][a][b] += dp[i][a][b] * (1 - pb[i / 2]);
      } else {
        dp[i + 1][a + 1][b] += dp[i][a][b] * pa[i / 2];
        dp[i + 1][a][b] += dp[i][a][b] * (1 - pa[i / 2]);
      }
    }
    S(s);
    int A = s[0] - '0', B = s[2] - '0';
    UL(std::format("Case {}: {:.2f}%", ++t, T[A][B] * 100));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"