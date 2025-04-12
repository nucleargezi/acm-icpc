#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  VEC(string, s, n);
  int ans{};
  FOR(x, n) FOR(y, m) FOR(xx, x, n) FOR(yy, y, m) {
      bool f{true};
      FOR(i, x, xx + 1) FOR(k, y, yy + 1) f &= s[i][k] == '0';
      if (f) chmax(ans, xx - x + 1 + yy - y + 1 << 1);
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