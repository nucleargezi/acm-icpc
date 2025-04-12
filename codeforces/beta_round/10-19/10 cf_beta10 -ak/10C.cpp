#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  ll c[9]{};
  FOR(i, 1, n + 1) ++c[i % 9];
  ll ans{};
  FOR(A, 9) FOR(B, 9) ans += c[A] * c[B] * c[A * B % 9];
  FOR(i, 1, n + 1) ans -= n / i;
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