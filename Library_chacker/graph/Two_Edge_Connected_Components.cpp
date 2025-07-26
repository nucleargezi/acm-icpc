#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/bcc_e.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  graph g(n);
  g.read_graph<false, 0>(m);
  meion [sz, bcc] = bcc_e(g);
  vector<vector<int>> ans(sz);
  FOR(i, len(bcc)) ans[bcc[i]] += i;
  print("{}", sz);
  for (meion &v : ans) {
    print("{} {}", len(v), v);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"