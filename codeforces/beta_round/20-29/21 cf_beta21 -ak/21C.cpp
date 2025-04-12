#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(ll, a, n);
  ll s{SUM(a)};
  if (s % 3) iroha UL(0);
  s /= 3;
  vector<ll> v(n);
  FOR(i, n - 1) a[i + 1] += a[i];
  FOR(i, n) v[i] = a[i] == s;
  FOR_R(i, n - 1) a[i + 1] -= a[i];
  FOR_R(i, n - 1) a[i] += a[i + 1];
  FOR(i, n) a[i] = a[i] == s;
  FOR_R(i, n - 1) a[i] += a[i + 1];
  ll ans{};
  FOR(i, n - 2) ans += v[i] * a[i + 2];
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