#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> fa(N, -1), dp(N);
  FOR(i, N) {
    dp[i] = a[i];
    if (i >= 2 and chmax(dp[i], dp[i - 2] + a[i])) fa[i] = i - 2;
    if (i >= 1 and chmax(dp[i], dp[i - 1])) fa[i] = i - 1; 
  }
  int i = max_element(all(dp)) - bg(dp);
  print(dp[i]);
  vc<int> pa;
  while (i != -1) {
    int f = fa[i];
    if (dp[i] - dp[f] == a[i]) pa.ep(i + 1);
    i = f;
  }
  reverse(pa);
  print(pa);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"