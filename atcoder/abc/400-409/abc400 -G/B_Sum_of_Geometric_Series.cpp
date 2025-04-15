#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  ll ans{};
  meion pow = [](ll a, ll b) -> ll {
    ll res{1};
    while (b) {
      if (b & 1) res *= a;
      a *= a;
      b >>= 1;
    }
    iroha res;
  };
  FOR(i, m + 1) {
    ans += pow(n, i);
    if (ans > 1'000'000'000) iroha UL("inf");
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