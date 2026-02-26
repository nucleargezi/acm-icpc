#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/modint.hpp"
#include "YRS/ds/fenw/fenw.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, M);
  retsu<int> a(N, M);
  FOR(i, N) FOR(k, M) IN(a[i][k]), a[i][k] -= a[i][k] != -1;

  retsu<int> vis(N + 1, M + 1), viss(N + 1, M + 1);
  FOR(i, N) FOR(k, M) if (a[i][k] != -1) {
    if (a[i][k] == i + k) {
      viss[i][k] = 1;
    } else if (a[i][k] == i + k + 1) {
      vis[i][k] = 1;
    } else return print(0);
  }
  vis[0][M] = 1;
  vis[N][0] = 1;
  FOR(i, N + 1) FOR(k, M + 1) {
    if (i) vis[i][k] |= vis[i - 1][k];
    if (k) vis[i][k] |= vis[i][k - 1];
  }
  FOR_R(i, N) FOR_R(k, M) {
    if (i + 1 < N) viss[i][k] |= viss[i + 1][k];
    if (k + 1 < M) viss[i][k] |= viss[i][k + 1];
  }
  FOR(i, N) FOR(k, M) if (vis[i][k]) {
    if (a[i][k] == -1) a[i][k] = i + k + 1;
    else if (a[i][k] != i + k + 1) return print(0);
  }
  FOR(i, N) FOR(k, M) if (viss[i][k]) {
    if (a[i][k] == -1) a[i][k] = i + k;
    else if (a[i][k] != i + k) return print(0);
  }
  if (vis[0][0]) return print(1);
  fenw<monoid_add<mint>> dp(M + 1);
  FOR(k, M) {
    if (not vis[0][k] and vis[0][k + 1]) {
      FOR(i, k + 2) if (not viss[0][i]) dp.multiply(i, 1);
    }
  }
  FOR(i, 1, N) {
    FOR(k, M + 1) if (not viss[i][k]) {
      if (not vis[i][k]) {
        dp.set(k, dp.prod(k, M + 1));
      } else {
        dp.set(k, dp.prod(k, M + 1));
        FOR(j, k + 1, M + 1) dp.set(j, 0);
        break;
      }
    }
  }
  print(dp.prod_all());
}
#include "YRS/aa/main.hpp"