#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  int f{}, ans{};
  FOR(n) {
    S(s);
    if (s == "login") f = 1;
    else if (s == "logout") f = 0;
    else if (s == "public") ;
    else ans += not f;
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