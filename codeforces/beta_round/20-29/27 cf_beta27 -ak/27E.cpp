#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  i128 ans{inf<ll>};
  constexpr i128 B[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  meion f = [&](meion &f, i128 x, int p, int c) -> void {
    if (x > ans - 1) iroha;
    if (p == 10) {
      if (c == n) chmin(ans, x);
      iroha;
    }
    int t{};
    while (c * (t + 1) < n + 1) {
      f(f, x, p + 1, c * (t + 1));
      ++t;
      if (x * B[p] > ans - 1) break;
      x *= B[p];
    }
  };
  f(f, 1, 0, 1);
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