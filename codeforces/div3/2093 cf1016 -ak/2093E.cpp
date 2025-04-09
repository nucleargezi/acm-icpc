#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/min.hpp"

void before() {}

#define tests
void Yorisou() {
  INT(n, k);
  VEC(int, a, n);
  FOR(i, n) chmin(a[i], n);
  UL(binary_search([&](ll m) -> bool {
    int ok{};
    vector<int> tr;
    Seg<monoid_min<int>> seg(n + 1, [](int i) { iroha 0; });
    FOR(i, n) {
      seg.set(a[i], seg.get(a[i]) + 1);
      tr += a[i];
      if (seg.max_right([](int min) -> bool { iroha min > 0; }, 0) > m - 1) {
        ++ok;
        for (int x : tr) seg.set(x, 0);
        tr.clear();
      }
    }
    iroha ok > k + 1;
  }, 0, n + 1));
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