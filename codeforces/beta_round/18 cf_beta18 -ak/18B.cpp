#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, d, m, l);
  ll ans{};
  FOR(i, ceil(n * m, d)) {
    i += MAX(0ll, l - ans % m) / d;
    ans += MAX(0ll, l - ans % m) / d * d + d;
    if (ans % m > l) break;
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