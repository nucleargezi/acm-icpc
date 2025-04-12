#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  VEC(PLL, a, n);
  VEC(ll, line, m);
  meion dis = [&](int x, int y) -> ll {
    iroha ABS(a[x].first - a[y].first) + ABS(a[x].second - a[y].second);
  };
  meion ck = [&](int s) -> bool {
    map<ll, vector<ll>> M;
    FOR(i, m) M[line[i]] += i;
    vector<int> ans(n, -1);
    FOR(i, s, n, 2) {
      ll x{dis((i + n - 1) % n, (i + 1) % n)};
      if (M[x].empty()) {
        iroha false;
      }
      ans[i] = M[x].back() + 1;
      M[x].pop_back();
    }
    YES();
    UL(ans);
    iroha true;
  };
  if (not ck(0) and not ck(1)) NO();
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