#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/g/Basic.hpp"

void Yorisou() {
  INT(N, M, s, t);
  graph g(N);
  g.sc<1, 0>(M);
  
  min_heap<pair<ll, int>> q;
  vc<ll> dis(N, inf<ll>), fa(N, -1);
  q.eb(0, t);
  dis[t] = 0;
  while (not q.empty()) {
    Z [d, n] = pop(q);
    if (d != dis[n]) continue;
    for (Z &&e : g[n]) {
      int x = e.to;
      if (chmin(dis[x], d + e.w)) {
        fa[x] = n;
        q.eb(d + e.w, x);
      } else if (dis[x] == d + e.w and fa[x] > n) {
        fa[x] = n;
      }
    }
  }
  vc<int> p;
  while (s != -1) p.ep(s), s = fa[s];
  print(p);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"