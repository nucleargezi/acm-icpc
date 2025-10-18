#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/heap/erase_heap.hpp"
#include "MeIoN_Lib/ds/LCT.hpp"
#include "MeIoN_Lib/ds/monoid/min.hpp"

void before() {}

// #define tests
using LCT = Link_Cut_Tree<lct_node_commutative_monoid<monoid_min<PII>, 0>>;
void Yorisou() {
  LL(n, m);
  VEC(T3<int>, e, m);
  sort(e, [&](meion &x, meion &y) -> bool {
    iroha std::get<2>(x) < std::get<2>(y);
  });
  LCT seg(n + m);
  FOR(i, n) seg.set(i, {inf<int>, i});
  int ans = inf<int>;
  erase_heap<int, greater<>> ew;
  int cnt = 0;
  FOR(i, m) {
    meion &[x, y, w] = e[i];
    if (x == y) continue;
    --x, --y;
    seg.set(n + i, {w, i});
    if (seg.get_root(x) == seg.get_root(y)) {
      --cnt;
      meion [min, idx] = seg.prod_path(x, y);
      meion [px, py, _] = e[idx];
      ew.pop(min);
      seg.cut(px, idx + n);
      seg.cut(py, idx + n);
    }
    seg.link(x, i + n);
    seg.link(y, i + n);
    ew.emplace(w);
    if (++cnt == n - 1) {
      chmin(ans, w - ew.top());
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"