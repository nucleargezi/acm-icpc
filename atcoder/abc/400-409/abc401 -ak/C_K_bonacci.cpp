#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<1'000'000'000>;
void Yorisou() {
  INT(n, k);
  Seg<monoid_add<mint>> seg(++n, [](int i) { iroha 1; });
  FOR(i, k, n) {
    seg.set(i, seg.prod(i - k, i));
  }
  UL(seg.get(n - 1));
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}