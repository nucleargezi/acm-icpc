#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/prims_test.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  int ans{};
  FOR(i, 6, n + 1) {
    ans += len(factor(i)) == 2;
  }
  UL(ans);
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