#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/tree_monoid_lazy.hpp"
#include "YRS/ds/monoid/add.hpp"

// #define tests
struct monoid_X {
  using X = struct {
    int min, max, L, R;
  };

  static constexpr X op(const X &L, const X &R) {
    X res;
    res.max = std::max(L.max, R.max);
    res.min = std::min(L.min, R.min);
    res.L = std::max({L.L, R.L, L.max - R.min});
    res.R = std::max({L.R, R.R, R.max - L.min});
    return res;
  }
  static constexpr X unit() { return {inf<int> / 2, -inf<int> / 2, 0, 0}; }
  static constexpr X make(int x) { return {x, x, 0, 0}; }
  static constexpr bool commute = false;
};
struct mono {
  using MX = monoid_X;
  using MA = monoid_add<int>;
  using X = MX::X;
  using A = MA::X;

  static constexpr X act(const X &x, const A &a, ll) {
    X res = x;
    res.min += a, res.max += a;
    return res;
  }
};
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  graph g(N);
  g.read_tree();
  tree v(g);

  lazy_tree_monoid<decltype(v), mono> seg(
      v, [&](int i) -> mono::X { return mono::MX::make(a[i]); });
  INT(Q);
  FOR(Q) {
    INT(x, y, w);
    --x, --y;
    print(seg.prod_path(x, y).R);
    seg.apply_path(x, y, w);
  }
}
#include "YRS/Z_H/main.hpp"