#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  VEC(ll, b, m);
  sort(a, greater());
  sort(b, greater());
  a = pre_sum(a);
  b = pre_sum(b);
  FOR_R(i, n) chmax(a[i], a[i + 1]);
  ll ans{};
  FOR(i, MIN(n, m) + 1) {
    chmax(ans, a[i] + b[i]);
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