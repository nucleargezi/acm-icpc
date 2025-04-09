#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/rectangle_union.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n, m, x, y, xx, yy);
  ll l{MIN(x, xx)}, r{MIN(n - x, n - xx)}, u{MIN(y, yy)}, d{MIN(m - y, m - yy)};
  rectangle_union<ll> g;
  g.add(x - l, y - u, x + r, y + d);
  g.add(xx - l, yy - u, xx + r, yy + d);
  UL(n * m - g.calc());
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