#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll ans = 0;
  FOR(i, 10) {
    bool h = 0, w = 0;
    for (ll x : a) {
      h |= x >> i & 1;
      w |= x >> i & 1 ^ 1;
    }
    if (h and w) ans |= 1ll << i;
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