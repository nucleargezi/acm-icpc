#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/lct/lct_act.hpp"
#include "YRS/ds/monoid/add.hpp"

struct monoid_X {
  using X = struct {
    int x, min, max, r;
  };
  static constexpr X unit() { return {}; }
  static constexpr X make(int x) { return {x, x, x, 0}; }
  static constexpr X op(X a, X b) {
    chmax(a.r, b.r);
    chmax(a.r, b.max - a.min);
    chmax(a.max, b.max);
    chmin(a.min, b.min);
    return a;
  }
  static constexpr bool commute = false;
};
struct AM {
  using MX = monoid_X;
  using MA = monoid_add<int>;
  using X = MX::X;
  using A = MA::X;
  static constexpr X act(X x, A a, int) {
    x.x += a, x.min += a, x.max += a;
    return x;
  }
};
using LCT = LCT_act<AM>;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  LCT lct(N, [&](int i) -> AM::X { return AM::MX::make(a[i]); });
  FOR(i, N - 1) {
    INT(x, y);
    --x, --y;
    lct.link(x, y);
  }
  INT(Q);
  FOR(Q) {
    INT(x, y, w);
    --x, --y;
    print(lct.prod(x, y).r);
    lct.apply(x, y, w);
  }
}
#include "YRS/Z_H/main.hpp"