#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  VVEC(char, a, n, m);
  int x{inf<int>}, y{x}, xx{-x}, yy{-x};
  FOR(i, n) FOR(k, m) if (a[i][k] == '*') {
    chmin(x, i), chmax(xx, i);
    chmin(y, k), chmax(yy, k);
  }
  if (x == inf<int>) iroha;
  FOR(i, x, xx + 1) {
    UL(string{a[i].begin() + y, a[i].begin() + yy + 1});
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
  Yorisou();
  iroha 0;
}