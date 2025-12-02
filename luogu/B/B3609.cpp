#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/graph/Apck/scc.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  graph<int, 1> g(N);
  g.read_graph(M);
  Z [c, id] = scc_id(g);
  Z scc = get_scc_group(c, id);
  print(c);
  FOR(i, c) for (int &x : scc[i]) ++x;
  vc<char> vis(c);
  FOR(i, N) if (not vis[id[i]]) vis[id[i]] = 1, print(scc[id[i]]);
}
#include "YRS/Z_H/main.hpp"