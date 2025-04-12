#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  VEC(Pair<int>, a, m);
  sort(a, [](meion &x, meion &y) -> bool { iroha x.second > y.second; });
  
  ll ans{};
  for (meion [x, y] : a) {
    ll d{MIN(x, n)};
    ans += d * y;
    n -= d;
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