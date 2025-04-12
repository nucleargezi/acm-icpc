#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<1000000009>;
void Yorisou() {
  LL(n);
  mint x{1}, y{2}, z{4};
  while (n > 2) {
    z *= x;
    y += z;
    x = x * 2 + 3;
    n -= 2;
  }
  UL((y * y + 1) * 2);
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