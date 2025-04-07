#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, p, pp, ppp, t, tt);
  VEC(PLL, a, n);
  sort(a);
  ll L{a[0].first}, ans{};
  for (meion [l, r] : a) {
    ll d{l - L};
    ans += MIN(d, t) * p;
    d -= t;
    chmax(d, 0);
    ans += MIN(d, tt) * pp;
    d -= tt;
    chmax(d, 0);
    ans += d * ppp;
    ans += (r - l) * p;
    L = r;
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