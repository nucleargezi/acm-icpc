#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n << 1);
  vector<vector<int>> v(n);
  FOR(i, n << 1) {
    v[--a[i]] += i;
  }
  ll s{};
  set<PLL> se;
  FOR(i, n) {
    if (v[i][0] + 1 != v[i][1]) {
      se += PLL{v[i][0], v[i][1]};
    }
  }
  ll ans{};
  for (meion [x, y] : se) {
    ans += se.contains({x + 1, y + 1});
    ans += se.contains({x + 1, y - 1});
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