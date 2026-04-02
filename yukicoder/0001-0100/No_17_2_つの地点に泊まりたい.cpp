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
  INT(N);
  VEC(int, s, N);
  retsu<ll> dis(N, N, inf<int>);
  INT(M);
  FOR(M) {
    INT(f, t, w);
    dis[f][t] = dis[t][f] = w;
  }
  FOR(m, N) FOR(i, N) FOR(k, N) chmin(dis[i][k], dis[i][m] + dis[m][k]);
  ll ans = inf<ll>;
  FOR(f, N) FOR(t, N) if (f != t and min(f, t) != 0 and max(f, t) != N - 1) {
    chmin(ans, dis[0][f] + dis[f][t] + dis[t][N - 1] + s[f] + s[t]);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"