#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/string/SAM.hpp"

// #define tests
void Yorisou() {
  STR(s);
  int N = len(s);
  FOR(i, N) s[i] -= 'a';
  INT(T, K);
  sam seg(N << 1);
  vector<int> sz = seg.build(s);
  const int M = len(seg);
  if (T == 0) FOR(i, 1, M) sz[i] = 1;
  sz[0] = 0;
  vector<u8> vis(M);
  vector<ll> dp(all(sz));
  Z f = [&](Z &f, int n) -> void {
    if (vis[n]) return;
    vis[n] = 1;
    FOR(i, 26) {
      int x = seg[n][i];
      if (x == -1) continue;
      f(f, x);
      dp[n] += dp[x];
    }
  };
  f(f, 0);
  if (dp[0] < K) return print(-1);
  string ans;
  for (int p = 0; K > 0; ) {
    FOR(i, 26) {
      int x = seg[p][i];
      if (x == -1) continue;
      if (K > dp[x]) {
        K -= dp[x];
      } else {
        p = x;
        K -= sz[p];
        ans += char('a' + i);
        break;
      }
    }
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"