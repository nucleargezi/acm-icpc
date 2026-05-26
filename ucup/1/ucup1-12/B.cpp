#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  retsu<int> dp(N + 1, 10000, -1);
  vc<int> s;
  while (K) s.ep(K % 10), K /= 10;
  sort(s);
  do {
    int n = 0;
    for (int x : s) n = n * 10 + x;
    dp[0][n] = 0;
  } while (next_permutation(all(s)));
  FOR(i, N) {
    int x = a[i];
    vc<int> s;
    FOR(k, 10000) if (dp[i][k] != -1) {
      int f = dp[i][k];
      chmax(dp[i + 1][k], f);
      s.clear();
      int e = k;
      while (e) s.ep(e % 10), e /= 10;
      sort(s);
      do {
        int n = 0;
        for (int e : s) n = n * 10 + e;
        if (n >= x) chmax(dp[i + 1][n - x], f + 1);
      } while (next_permutation(all(s)));
    }
  }
  int rs = 0;
  FOR(i, 10000) chmax(rs, dp[N][i]);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}