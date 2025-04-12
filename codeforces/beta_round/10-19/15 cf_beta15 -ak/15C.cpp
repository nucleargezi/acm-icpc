#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(Pair<ll>, a, n);
  meion f = [&](ll x) -> ll {
    ll y{x % 4};
    iroha y == 0 ? x : y == 1 ? 1 : y == 2 ? x + 1 : 0;
  };
  ll s{};
  for (meion [x, y] : a) {
    s ^= f(x - 1) ^ f(x + y - 1);
  }
  UL(s ? "tolik" : "bolik");
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