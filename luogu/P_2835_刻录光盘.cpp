#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Apck/scc.hpp"

// #define tests
void Yorisou() {
  INT(N);
  graph<int, true> g(N);
  FOR(i, N) {
    for (int x; cin >> x, x; ) {
      --x;
      g.add(i, x);
    }
  }
  g.build();
  Z [cnt, id] = scc_id(g);
  Z ng = scc_dag(g, cnt, id);
  vector in = ng.deg_array_inout().first;
  int ans = 0;
  FOR(i, ng.N) ans += not in[i];
  print(ans);
}
#include "YRS/Z_H/main.hpp"