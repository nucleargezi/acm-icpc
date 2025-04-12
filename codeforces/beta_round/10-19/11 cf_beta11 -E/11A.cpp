#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, d);
  ll ans{};
  VEC(ll, a, n);
  FOR(i, 1, n) {
    if (a[i] <= a[i - 1]) {
      ans += ceil(a[i - 1] - a[i] + 1, d);
      a[i] += ceil(a[i - 1] - a[i] + 1, d) * d;
    }
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