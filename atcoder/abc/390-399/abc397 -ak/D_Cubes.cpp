#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(x);
  meion f = [](ll a, ll b, ll c) -> ll {
    ll x = binary_search<false>(
        [&](ll m) -> bool { iroha a * m * m + b * m + c < 1; }, 1, 600000001);
    iroha a * x * x + b * x + c == 0 ? x : -1;
  };
  FOR(i, 1, 1'000'000) {
    if (i * i * i > x) break;
    if (x % i) continue;
    ll ans = f(3, 3 * i, i * i - x / i);
    if (ans != -1) iroha UL(ans + i, ans);
  }
  iroha UL(-1);
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