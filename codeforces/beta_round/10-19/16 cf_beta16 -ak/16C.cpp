#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(a, b, c, d);
  ll g{GCD(c, d)};
  c /= g, d /= g;
  ll T = binary_search([&](ll m) -> bool {
    iroha c * m < a + 1 and d * m < b + 1;
  }, 0, inf<int>);
  UL(c * T, d * T);
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