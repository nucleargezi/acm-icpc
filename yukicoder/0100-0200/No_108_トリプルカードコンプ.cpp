#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = ld;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  FOR(i, N) chmin(a[i], 3);
  vc<int> c(4);
  for (int x : a) ++c[x];
  retsu<array<re, 101>> dp(N + 1, N + 1);
  retsu<bitset<101>> vis(N + 1, N + 1);
  vis[0][0][0] = 1;
  dp[0][0][0] = 0;
  Z f = [&](Z &f, int i, int k, int j) -> re {
    if (vis[i][k][j]) return dp[i][k][j];
    vis[i][k][j] = 1;
    re s = N;
    if (i != 0) s += f(f, i - 1, k + 1, j) * i;
    if (k != 0) s += f(f, i, k - 1, j + 1) * k;
    if (j != 0) s += f(f, i, k, j - 1) * j;
    return dp[i][k][j] = s / (i + k + j);
  };
  setp(10);
  print(f(f, c[0], c[1], c[2]));
}
#include "YRS/aa/main.hpp"