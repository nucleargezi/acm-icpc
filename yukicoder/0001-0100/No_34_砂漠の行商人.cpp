#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, V, sy, sx, ty, tx);
  --sx, --sy, --tx, --ty;
  retsu<int> a(N, N), dp(N, N, inf<int>), ndp(N, N);
  IN(a);
  dp[sx][sy] = 0;
  FOR(i, N * N) {
    ndp.fill(inf<int>);
    FOR(x, N) FOR(y, N) if (dp[x][y] != inf<int>) {
      static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
      FOR(d, 4) {
        int xx = x + dx[d], yy = y + dy[d];
        if (min(xx, yy) >= 0 and max(xx, yy) < N) {
          chmin(ndp[xx][yy], dp[x][y] + a[xx][yy]);
        }
      }
    }
    swap(dp, ndp);
    if (dp[tx][ty] < V) return print(i + 1);
  }
  print(-1);
}
#include "YRS/aa/main.hpp"