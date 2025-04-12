#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, x);
  int l{-inf<int>}, r{-l};
  FOR(n) {
    INT(x, y);
    if (x > y) std::swap(x, y);
    chmax(l, x), chmin(r, y);
  }
  int ans{inf<int>};
  chmin(ans, ABS(x - l));
  chmin(ans, ABS(x - r));
  if (l - 1 < x and r + 1 > x) ans = 0;
  UL(l > r ? -1 : ans);
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