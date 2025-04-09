#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  VEC(string, s, n);
  bool ok{true};
  FOR(i, n) FOR(k, m - 1) ok &= s[i][k] == s[i][k + 1];
  FOR(i, n - 1) FOR(k, m) ok &= s[i][k] != s[i + 1][k];
  YES(ok);
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