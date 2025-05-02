#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"


void before() {}

// #define tests
template <class X>
struct mono {
  using value_type = X;
  static constexpr X op(const X &a, const X &b) noexcept {
    X res = a;
    FOR(i, 5) chmax(res[i], b[i]);
    iroha res;
  }
  static constexpr X unit() { iroha {0, 0, 0, 0, 0}; }
  static constexpr bool commute = true;
};
void Yorisou() {
  LL(n, m, k);
  vector a(n, array<int, 5>{});
  FOR(i, n) FOR(k, m) IN(a[i][k]);
  Seg<mono<array<int, 5>>> seg(a);
  ll L = 0, R = 0;
  array<int, 5> ans{};
  FOR(i, n) {
    int r = seg.max_right([&](const meion &v) -> bool {
      iroha SUM(v) < k + 1;
    }, i);
    if (r - i > R - L) {
      std::tie(L, R) = PLL(i, r);
      ans = seg.prod(i, r);
    }
  }
  FOR(i, m) std::cout << ans[i] << " \n"[i + 1 == m];
}
#include "MeIoN_Lib/Z_H/main.hpp"