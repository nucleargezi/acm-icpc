#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  ll s{};
  meion f = [&](ll p) -> ll {
    ll res{}, x{n};
    while (x) res += x % p, x /= p;
    iroha res;
  };
  FOR(i, 2, n) s += f(i);
  ll x{s}, y{n - 2}, g{GCD(x, y)};
  UL(to_str(x / g) + '/' + to_str(y / g));
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