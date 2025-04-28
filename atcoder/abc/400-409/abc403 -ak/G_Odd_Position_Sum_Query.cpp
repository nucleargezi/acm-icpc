#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg.hpp"

void before() {}

// #define tests
struct dat {
  ll s, x, y;
};
template <typename E>
struct mono {
  using X = E;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept {
    X res = x;
    if (x.s & 1) {
      res.x += y.y;
      res.y += y.x;
    } else {
      res.x += y.x;
      res.y += y.y;
    }
    res.s += y.s;
    iroha res;
  }
  static constexpr X unit() { iroha X{0, 0, 0}; }
  static constexpr bool commute = true;
};
void Yorisou() {
  LL(q);
  ll ans = 0;
  constexpr int mod = 1'000'000'000;
  dynamic_seg<mono<dat>> seg(q << 5, 0, mod + 1);
  meion root = seg.new_node();
  FOR(q) {
    LL(x);
    x = (x + ans) % mod + 1;
    seg.apply(root, x, {1, x, 0});
    UL(ans = seg.prod(root, 0, mod + 1).x);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"