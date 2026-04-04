#include "YRS/all.hpp"

vc<int> read() {
  STR(s);
  char ii[1000]{};
  fill(ii, ii + 1000, 50);
  for (int t = 0; int c : "KUROI") ii[c] = t++;
  ii['?'] = 5;
  int n = si(s);
  vc<int> a(n);
  FOR(i, n) a[i] = ii[(int)s[i]];
  return a;
}
void Yorisou() {
  vc<int> s = read();
  int N = si(s);
  static char dp[101][21][21][21][21];
  memset(dp, -1, sizeof dp);
  dp[0][0][0][0][0] = 0;
  int ans = 0;
  FOR(i, N) FOR(a, 21) FOR(b, a + 1) FOR(c, b + 1) FOR(d, c + 1) {
    int f = dp[i][a][b][c][d];
    if (f != -1) {
      if (s[i] == 0 or s[i] == 5) if (a < 20) chmax(dp[i + 1][a + 1][b][c][d], f);
      if (s[i] == 1 or s[i] == 5) if (b < a) chmax(dp[i + 1][a][b + 1][c][d], f);
      if (s[i] == 2 or s[i] == 5) if (c < b) chmax(dp[i + 1][a][b][c + 1][d], f);
      if (s[i] == 3 or s[i] == 5) if (d < c) chmax(dp[i + 1][a][b][c][d + 1], f);
      if (s[i] == 4 or s[i] == 5) {
        if (d > f) {
          chmax(dp[i + 1][a][b][c][d], f + 1);
          chmax(ans, f + 1);
        }
      }
      chmax(dp[i + 1][a][b][c][d], f);
    }
  }
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"