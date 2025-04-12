#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(T4<ll>, a, n);
  static map<ll, pair<ll, ll>> dp[300001];
  static ll fa[100001];
  memset(fa, -1, sizeof fa);
  pair<ll, ll> ans{-1, -1};
  FOR(i, n) {
    meion [v, c, l, r] = a[i];
    ll s{c + l + r};
    if (dp[s].contains(l)) {
      v += dp[s][l].first;
      fa[i] = dp[s][l].second;
    } else if (l) {
      v = -inf<ll>;
    }
    not r and chmax(ans, pair(v, i));
    chmax(dp[s][s - r], pair(v, i));
  }
  ll p = ans.second;
  vector<ll> path;
  while (~p) path += p + 1, p = fa[p];
  reverse(path);
  UL(len(path));
  UL(path);
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