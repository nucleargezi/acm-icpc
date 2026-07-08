#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  VEC(string, a, N);

  static int dp[50][50][50][50];
  Z f = [&](Z &f, int l, int r, int L, int R) {
    if (l > r or L > R) return 0;
    if (dp[l][r][L][R] != -1) return dp[l][r][L][R];
    set<int> se;
    FOR(x, N) FOR(y, M) {
      int s = x + y, t = x - y + 20;
      if (s % 2 == l % 2 and s >= l and s <= r and t >= L and t <= R) {
        if (a[x][y] == 'L') {
          se.eb(f(f, l, s - 2, L, R) ^ f(f, s + 2, r, L, R));
        } else if (a[x][y] == 'R') {
          se.eb(f(f, l, r, L, t - 2) ^ f(f, l, r, t + 2, R));
        } else {
          se.eb(f(f, l, s - 2, L, t - 2) ^ f(f, l, s - 2, t + 2, R) ^
                f(f, s + 2, r, L, t - 2) ^ f(f, s + 2, r, t + 2, R));
        }
      }
    }
    int rs = 0;
    while (se.contains(rs)) ++rs;
    return dp[l][r][L][R] = rs;
  };
  
  memset(dp, -1, sizeof dp);
  print((f(f, 0, 40, 0, 40) ^ f(f, 1, 39, 1, 39)) ? "WIN" : "LOSE");
}

int main() {
  Yorisou();
  return 0;
}