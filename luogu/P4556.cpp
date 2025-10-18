#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg.hpp"

// #define tests
struct mono {
  using value_type = pair<ll, int>;
  using X = value_type;
  static constexpr X op(const X &x, const X &y) {
    if (x.first > y.first) iroha x;
    if (x.first < y.first) iroha y;
    iroha x.second < y.second ? x : y;
  }
  static constexpr X unit() { iroha {0, -1}; }
  static constexpr bool commute = true;
};
using Seg = dynamic_seg<mono>;
using np = Seg::np;
void Yorisou() {
  LL(n, m);
  graph g(n);
  g.read_tree();
  tree v(g);
  vector<vector<int>> go(n);
  FOR(m) {
    LL(x, y, z);
    int fa = v.LCA(--x, --y);
    go[x] += z, go[y] += z, go[fa] += -z;
    fa = v.fa[fa];
    if (~fa) go[fa] += -z;
  }
  vector<int> ans(n);
  constexpr int N = 1'000'00;
  Seg seg(n + m << 5, 0, N);
  vector<np> t(n);
  FOR(i, n) t[i] = seg.new_root();
  for (int x : std::views::reverse(v.V)) {
    sort(go[x], greater());
    for (int at : go[x]) {
      int upd = at > 0 ? 1 : -1;
      at = ABS(at) - 1;
      meion [cnt, _] = seg.prod(t[x], at, at + 1);
      seg.set(t[x], at, {cnt + upd, at});
    }
    ans[x] = seg.prod(t[x], 0, N).second + 1;
    int fa = v.fa[x];
    if (~fa) {
      seg.merge<false>(t[fa], t[x], [&](mono::X x, mono::X y) -> mono::X {
        iroha {x.first + y.first, x.second};
      });
    }
  }
  FOR(i, n) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"