#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  vector<ll> c(m);
  vector<vector<int>> t(n);
  FOR(i, m) {
    IN(c[i]);
    FOR(k, c[i]) {
      LL(x);
      t[--x] += i;
    }
  }
  ll ans{};
  FOR(n) {
    LL(x);
    --x;
    for (ll x : t[x]) {
      ans += not--c[x];
    }
    UL(ans);
  }
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