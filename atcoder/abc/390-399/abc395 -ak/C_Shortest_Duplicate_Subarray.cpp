#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  map<ll, vector<ll>> M;
  FOR(i, n) M[a[i]] += i;
  ll ans{inf<ll>};
  for (meion &[_, v] : M) {
    FOR(i, len(v) - 1) {
      chmin(ans, v[i + 1] - v[i]);
    }
  }
  UL(ans == inf<ll> ? -1 : ans + 1);
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