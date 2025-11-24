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
  INT(N, M, x, y);
  --x, --y;
  vc<vc<PII>> g(N);
  FOR(i, N) g[i].reserve(N);
  FOR(M) {
    INT(x, y, w);
    --x, --y;
    g[x].ep(y, w), g[y].ep(x, w);
  }
  retsu<ll> dis(N, N, inf<ll>);
  FOR(s, N) {
    min_heap<pair<ll, int>> q;
    q.eb(0, s);
    dis[s][s] = 0;
    while (not q.empty()) {
      Z [d, n] = pop(q);
      if (d != dis[s][n]) continue;
      for (Z [t, w] : g[n])
        if (chmin(dis[s][t], d + w)) q.eb(d + w, t);
    }
  }
  FOR(i, N) g[i].clear();
  FOR(i, N) {
    INT(t, w);
    FOR(k, N) if (dis[i][k] <= t) g[i].ep(k, w);
  }
  min_heap<pair<ll, int>> q;
  q.eb(0, x);
  vector<ll> dist(N, inf<ll>);
  dist[x] = 0;
  while (not q.empty()) {
    Z [d, n] = pop(q);
    if (d != dist[n]) continue;
    for (Z [t, w] : g[n]) 
      if (chmin(dist[t], d + w)) q.eb(d + w, t);
  }
  print(dist[y] == inf<ll> ? -1 : dist[y]);
}
#include "YRS/Z_H/main.hpp"