#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector<ll> c(30);
  for (ll x : a) FOR(i, 30) if (x >> i & 1)++ c[i];
  ll ans{};
  for (ll x : a) {
    ll t{};
    FOR(i, 30) {
      if (x >> i & 1) {
        t += (n - c[i]) * (1 << i);
      } else {
        t += c[i] * (1 << i);
      }
    }
    chmax(ans, t);
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