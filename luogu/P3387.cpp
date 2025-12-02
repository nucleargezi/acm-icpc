#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/graph/Apck/scc.hpp"
#include "YRS/ds/basic/queue.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  graph<int, 1> g(N);
  g.read_graph(M);
  Z [c, id] = scc_id(g);
  Z ng = scc_dag(g, c, id);
  vc<int> in = ng.deg_array_inout().fi;
  queue<int> q;
  vc<ll> na(c), f(c);
  FOR(i, N) na[id[i]] += a[i];
  FOR(i, c) if (in[i] == 0) q.eb(i);
  ll ans = -1;
  while (not q.empty()) {
    int n = pop(q);
    f[n] += na[n];
    chmax(ans, f[n]);
    for (Z &&e : ng[n]) {
      chmax(f[e.to], f[n]);
      if (--in[e.to] == 0) q.eb(e.to);
    }
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"