#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
void Yorisou() {
  LL(n);
  vector<int> x[3];
  FOR(i, n) {
    CH(c);
    if (c == 'R') x[0] += i;
    if (c == 'G') x[1] += i;
    if (c == 'B') x[2] += i;
  }
  graph G(n);
  G.read_tree();
  int ans = 0;
  FOR(i, 3) {
    if (len(x[i]) == n) continue;
    int rt = 0;
    FOR(k, 3) if (k != i and len(x[k])) rt = x[k][0];
    tree v(G, rt);
    sort(x[i], [&](int a, int b) { iroha v.L[a] > v.L[b]; });
    tree_monoid<decltype(v), monoid_add<int>> seg(v, [](int i) { iroha 1; });
    for (int x : x[i]) {
      seg.set(x, 0);
      if (not seg.prod_subtree(x)) continue;
      ++ans;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"