#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(PLL, a, m);
  map<ll, ll> M;
  for (meion [x, y] : a) {
    ll m = x + y;
    if (m > n) m -= n;
    ++M[m];
  }
  ll ans{m * (m - 1) >> 1};
  for (meion &[_, y] : M) {
    ans -= y * (y - 1) >> 1;
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