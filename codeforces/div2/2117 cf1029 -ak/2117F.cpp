#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

#define tests
using mint = M17;
void Yorisou() {
  LL(n);
  graph g(n);
  g.read_tree();
  tree v(g);
  ll c = 0;
  vector<int> lf;
  FOR(i, n) if (not len(v.collect_child(i))) {
    ++c;
    lf.emplace_back(i);
  }
  if (c > 2) iroha UL(0);
  if (c == 1) iroha UL(mint(2).pow(n));
  int x = lf[0], y = lf[1], A = v.LCA(x, y);
  mint ans;
  FOR(2) {
    swap(x, y);
    int a = v.dist(x, A), b = v.dist(y, A);
    if (a > b) ans += mint(2).pow(a - b - 1);
    else if (a < b) ans += mint(2).pow(b - a);
    else ans += 1;
  }
  UL(ans * mint(2).pow(v.deep[A] + 1));
}
#include "MeIoN_Lib/Z_H/main.hpp"