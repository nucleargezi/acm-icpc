#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  vector f(m, dsu(n));
  FOR(m) {
    LL(x, y, w);
    f[--w].merge(--x, --y);
  }
  LL(q);
  FOR(q) {
    LL(x, y);
    --x, --y;
    ll ans{};
    FOR(i, m) ans += f[i][x] == f[i][y];
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