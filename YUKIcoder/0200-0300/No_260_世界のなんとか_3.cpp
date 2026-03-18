#include "YRS/all.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M11;
mint f(const string &s) {
  int N = len(s);
  mint dp[2][2][3][8], ndp[2][2][3][8];
  dp[1][0][0][0] = 1;
  FOR(i, N) {
    int x = s[i] - '0';
    FOR(i, 2) FOR(k, 2) FOR(j, 3) FOR(l, 8) ndp[i][k][j][l] = 0;
    FOR(k, 2) FOR(j, 3) FOR(l, 8) {
      FOR(x, 10) {
        ndp[0][k | (x == 3)][(j * 10 + x) % 3][(l * 10 + x) % 8] += dp[0][k][j][l];
      }
      FOR(y, x) {
        ndp[0][k | (y == 3)][(j * 10 + y) % 3][(l * 10 + y) % 8] += dp[1][k][j][l];
      }
      ndp[1][k | (x == 3)][(j * 10 + x) % 3][(l * 10 + x) % 8] += dp[1][k][j][l];
    }
    FOR(i, 2) FOR(k, 2) FOR(j, 3) FOR(l, 8) dp[i][k][j][l] = ndp[i][k][j][l];
  }
  mint rs;
  FOR(i, 2) {
    FOR(k, 3) FOR(j, 1, 8) rs += dp[i][1][k][j];
    FOR(j, 1, 8) rs += dp[i][0][0][j];
  }
  return rs;
} 
void Yorisou() {
  STR(a, b);
  FOR_R(i, len(a)) if (a[i] != '0') {
    --a[i];
    FOR(k, i + 1, len(a)) a[k] += 9;
    break;
  }
  if (a[0] == '0') a.erase(0, 1);
  print(f(b) - f(a));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"