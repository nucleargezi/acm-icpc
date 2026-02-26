#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = ld;
using T = tuple<int, int, re>;
void Yorisou() {
  INT(x, y, N);
  VEC(T, a, N);
  re al = 0;
  for (Z &[xx, yy, c] : a) {
    al += c;
    xx -= x;
    yy -= y;
  }
  retsu<re> dp(1 << N, N, inf<re>);
  FOR(i, N) {
    Z [xx, yy, w] = a[i];
    dp[1 << i][i] = (al + 100) * (abs(xx) + abs(yy)) / 120 + w;
  }
  FOR(s, 1 << N) {
    re c = al;
    FOR(i, N) if (s >> i & 1) c -= get<2>(a[i]);
    FOR(i, N) if ((s >> i & 1) and dp[s][i] != inf<re>) {
      Z [x, y, w] = a[i];
      FOR(k, N) if ((s >> k & 1) == 0) { 
        Z [xx, yy, ww] = a[k];
        int d = abs(xx - x) + abs(yy - y);
        chmin(dp[1 << k | s][k], dp[s][i] + (c + 100) * d / 120 + ww);
      }
    }
  }
  re s = inf<re>;
  FOR(i, N) { 
    Z [x, y, c] = a[i];
    chmin(s, dp[(1 << N) - 1][i] + (abs(x) + abs(y)) * 100.l / 120); 
  }
  setp(10);
  print(s);
}
#include "YRS/aa/main.hpp"