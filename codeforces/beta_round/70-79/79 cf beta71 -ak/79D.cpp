#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/graph/Apck/bfs.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K, L);
  VEC(int, x, K);
  VEC(int, a, L);
  vector<int> c(N + 1), id(N + 1, -1);
  for (int x : x) c[x] = 1, c[x - 1] ^= 1;
  int t = 0;
  FOR(i, N + 1) if (c[i]) id[i] = t++;
  graph g(N + 1);
  for (int x : a) FOR(k, N + 1 - x) g.add(k, k + x);
  g.build();
  retsu<int> dis(t, t, inf<int> / 4);
  FOR(i, N + 1) if (c[i]) {
    vector dist = bfs(g, i).fi;
    FOR(t, N + 1) if (c[t] and dist[t] != inf<int>) 
      dis[id[i]][id[t]] = dist[t];
  }
  vector<int> dp(1 << t, inf<int> / 4);
  dp[0] = 0;
  FOR(s, 1, 1 << t) if (not(pc(s) & 1)) 
    for (int a = s, i = a & -a; a; a -= i, i = a & -a) 
      for (int b = a - i, k = b & -b; b; b -= k, k = b & -b) 
        chmin(dp[s], dp[s - i - k] + dis[lowbit(i)][lowbit(k)]);
  print(dp.back() == inf<int> / 4 ? -1 : dp.back());
}
#include "YRS/Z_H/main.hpp"