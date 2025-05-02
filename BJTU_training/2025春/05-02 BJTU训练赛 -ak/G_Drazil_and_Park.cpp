#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"

void before() {}

// #define tests
struct dat {
  ll a, b, c;
};
template <typename E>
struct mono {
  using X = E;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept {
    X ret = x;
    chmax(ret.a, y.a);
    chmax(ret.b, y.b);
    chmax(ret.c, y.c);
    chmax(ret.c, x.a + y.b);
    iroha ret;
  }
  static constexpr X unit() {
    iroha X {-inf<ll> / 4, -inf<ll> / 4, -inf<ll> / 4};
  }
  static constexpr bool commute = true;
};
void Yorisou() {
  LL(n, q);
  VEC(ll, d, n);
  VEC(ll, h, n);
  d += d;
  h += h;
  vector c = pre_sum(d);
  Seg<mono<dat>> seg(n << 1, [&](int i) {
    iroha dat{h[i] + h[i] - c[i], h[i] + h[i] + c[i], -inf<ll> / 4};
  });
  FOR(q) {
    LL(x, y);
    --x, --y;
    UL(x <= y ? seg.prod(y + 1, n + x).c : seg.prod(y + 1, x).c);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"