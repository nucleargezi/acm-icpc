#include "YRS/all.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/ds/basic/bs.hpp"

void Yorisou() {
  INT(N, K);
  if ((N & 1) or K >= N) return Impossible();
  retsu<int> c(K, N);
  vector bit(N, bs(N));
  FOR(i, N) bit[i].set(), bit[i].reset(i);
  bs vis(N);
  FOR(i, K) {
    vis.set();
    FOR(k, N) if (vis[k]) {
      vis.reset(k);
      int x = (vis & bit[k]).next(0);
      if (x == N) return Impossible();
      vis.reset(x);
      bit[k].reset(x);
      bit[x].reset(k);
      c[i][k] = x + 1;
      c[i][x] = k + 1;
    }
  }
  print(c);
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"