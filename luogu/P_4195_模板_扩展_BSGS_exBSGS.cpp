#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/discrete_log_fast.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
  ll a, mod, b;
  while (IN(a, mod, b), MAX(a, mod, b)) {
    ll ans = discrete_log(a, b, mod);
    if (ans == -1)
      UL("No Solution");
    else
      UL(ans);
  }
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
  MeIoN_is_UMP45();
  iroha 0;
}