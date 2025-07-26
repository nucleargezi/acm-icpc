#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/scc.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  graph<int, 1> g(n);
  g.read_graph<0, 0>(m);
  meion [cnt, id] = scc_id(g);
  meion scc = get_scc_group(cnt, id);
  meion v = scc_dag(g, cnt, id);

  vector in = v.deg_array_inout().first;
  queue<int> q;
  FOR(i, cnt) if (not in[i]) q.emplace_back(i);

  print("{}", cnt);
  while (not q.empty()) {
    int n = q.pop();
    print("{} {}", len(scc[n]), scc[n]);
    for (meion &&[ f, i, a, b ] : v[n]) {
      if (not --in[i]) q.emplace_back(i);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"