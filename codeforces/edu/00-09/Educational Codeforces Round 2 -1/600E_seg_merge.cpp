#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

// #define tests
struct mono {
  using X = struct {
    int c;
    ll s;
  };
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept {
    if (x.c == y.c) {
      iroha {x.c, x.s + y.s};
    }
    iroha x.c < y.c ? y : x;
  }
  static constexpr X unit() { iroha {0, 0}; }
  static constexpr bool commute = true;
};
using Seg = dynamic_seg<mono>;
using np = Seg::np;
void Yorisou() {
  LL(n);
  VEC(int, c, n);
  FOR(i, n) --c[i];
  graph g(n);
  g.read_tree();
  tree v(g);
  dynamic_seg<mono> seg(n << 5, 0, n);
  vector<np> t(n);
  FOR(i, n) t[i] = seg.new_root();
  vector<ll> ans(n);
  for (int x : std::views::reverse(v.V)) {
    meion [cnt, s] = seg.prod(t[x], c[x], c[x] + 1);
    ++cnt;
    s = c[x] + 1;
    seg.set(t[x], c[x], {cnt, s});
    ans[x] = seg.prod(t[x], 0, n).s;
    int fa = v.fa[x];
    if (fa != -1) {
      seg.merge<false>(t[fa], t[x], [](mono::X x, mono::X y) -> mono::X {
        iroha {x.c + y.c, x.s};
      });
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"