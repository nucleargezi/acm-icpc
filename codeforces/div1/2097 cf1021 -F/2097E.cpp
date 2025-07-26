#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/lct/LCT.hpp"
#include "MeIoN_Lib/ds/lct/node_commute_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

#define tests
using mono = monoid_add<ll>;
using lct_node = lct_node_commutative_monoid<mono>;
using LCT = Link_Cut_Tree<lct_node>;
void Yorisou() {
  LL(n, d);
  VEC(ll, a, n);
  LCT lct(n + 1);
  meion I = argsort(a);
  reverse(I);
  FOR(i, n) lct.link(i, i + 1);
  ll ans = 0;
  FOR(i, n) {
    int nx = i == n - 1 ? 0 : a[I[i + 1]];
    lct.cut(I[i], I[i] + 1);
    lct.set(I[i], 1);
    lct.link(I[i], MIN(n, I[i] + d));
    ans += (a[I[i]] - nx) * lct.prod_path(0, n);
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"