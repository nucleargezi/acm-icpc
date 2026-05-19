#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/bs.hpp"
#include "YRS/mod/barrett.hpp"

void Yorisou() {
  INT(N, M, P);
  VEC(int, a, N);
  VEC(int, b, M);

  vc<ll> dp(M);
  const barrett bt(P);
  Z w = [&](int x, int y) { return bt.mo(a[x] + b[y]); };
  bs vis(N * M);
  FOR(i, N) {
    if (i) {
      FOR(k, M) dp[k] = dp[k] + w(i - 1, k);
    }
    FOR(k, 1, M) {
      if (chmax(dp[k], dp[k - 1] + w(i, k - 1))) {
        vis.set(i * M + k);
      }
    }
  }
  
  print(dp[M - 1] + w(N - 1, M - 1));
  string s;
  for (int x = N - 1, y = M - 1; x or y; ) {
    if (x == 0) s += 'S', --y;
    else if (y == 0) s += 'C', --x;
    else {
      if (vis[x * M + y]) s += 'S', --y;
      else s += 'C', --x;
    }
  }
  reverse(s);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}