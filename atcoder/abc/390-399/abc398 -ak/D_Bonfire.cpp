#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, x, y);
  S(s);
  string ans(n, '0');
  ll a{}, b{};
  set<PLL> se{{0, 0}};
  FOR(i, n) {
    a += s[i] == 'S' ? -1 : s[i] == 'N' ? 1 : 0;
    b += s[i] == 'E' ? -1 : s[i] == 'W' ? 1 : 0;
    x += s[i] == 'S' ? -1 : s[i] == 'N' ? 1 : 0;
    y += s[i] == 'E' ? -1 : s[i] == 'W' ? 1 : 0;
    se += PLL(a, b);
    ans[i] += se.contains({x, y});
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