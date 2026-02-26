#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/g/steiner.hpp"
#include "YRS/ds/unionfind/dsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M, K);
  graph<int> g(N);
  g.sc<1>(M);
  VEC(int, s, K);
  FOR(i, K) --s[i];
  if (len(s) <= 15) return print(get<0>(steiner_tree(g, s)));
  
  vc<u8> is(N);
  for (int x : s) is[x] = 1;
  vc<int> n;
  FOR(i, N) if (is[i] == 0) n.ep(i);

  int sz = len(n), ans = inf<int>;
  Z es = g.es;
  sort(es, [&](Z &a, Z &b) { return a.w < b.w; });
  
  FOR(m, 1 << sz) {
    fill(all(is), 0);
    FOR(i, sz) if (m >> i & 1) is[n[i]] = 1;
    for (int x : s) is[x] = 1;
    dsu g(N);
    int sm = 0;
    for (Z &&e : es) {
      if (is[e.f] and is[e.to] and g.merge(e.f, e.to)) sm += e.w;
      if (sm >= ans) break; 
    }
    bool o = 1;
    FOR(i, 1, K) o &= g[s[i]] == g[s[i - 1]];
    if (o) chmin(ans, sm);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"