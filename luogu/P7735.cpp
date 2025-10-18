#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/tree_monoid_lazy.hpp"
#include "YRS/ds/monoid/set.hpp"

#define tests
struct monoid_X {
  using X = struct {
    int l, r, c;
  };

  static constexpr X op(const X &L, const X &R) {
    if (L.l == -1) return R;
    if (R.l == -1) return L;
    X res{L.l, R.r, L.c + R.c};
    res.c += L.r == R.l;
    return res;
  }
  static constexpr X unit() { return {-1, -1, 0}; }
  static constexpr X make(int x) { return {x, x, 0}; }
  static constexpr bool commute = false;
};
struct mono {
  using MX = monoid_X;
  using MA = monoid_set<int>;
  using X = MX::X;
  using A = MA::X;

  static constexpr X act(X x, A a, int size) {
    if (a.has_set) x = {a.set, a.set, size - 1};
    return x;
  }
};
using MX = mono::MX;
using MA = mono::MA;
void Yorisou() {
  INT(N, Q);
  graph g(N);
  g.read_tree();
  tree v(g);

  lazy_tree_monoid<decltype(v), mono> seg(v, [&](int i) -> MX::X {
    return MX::make(N + Q - i);
  });
  FOR(i, Q) {
    INT(op, x, y);
    --x, --y;
    if (op == 1) {
      seg.apply_path(x, y, MA::make_set(i));
    } else {
      print(seg.prod_path(x, y).c);
    }
  }
}
#include "YRS/Z_H/main.hpp"