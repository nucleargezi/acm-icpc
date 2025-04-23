#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, x);
  vector<ll> a(n), b(n);
  FOR(i, n) {
    IN(a[i], b[i]);
  }
  ll s{SUM(a) + SUM(b)};
  FOR(i, n - 1) chmin(a[i + 1], a[i] + x);
  FOR_R(i, n - 1) chmin(a[i], a[i + 1] + x);
  ll h{inf<ll>};
  FOR(i, n) chmin(h, a[i] + b[i]);
  UL(s - n * h);
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