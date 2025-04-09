#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  INT(n, m);
  VEC(string, a, n);
  VVEC(string, b, m, n);
  FOR(i, n) {
    bool f{};
    FOR(k, m) f |= a[i] == b[k][i];
    if (not f) iroha UL(-1);
  }
  ll ans{inf<ll>};
  FOR(i, m) {
    int s{};
    FOR(k, n) s += b[i][k] == a[k];
    chmin(ans, n + (n - s << 1));
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