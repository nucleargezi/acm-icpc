#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
constexpr ll INF = inf<ll> >> 2;
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  static ll dp[420][421][421];
  u8 lg[n + 1][n + 1]{};
  FOR(l, n) FOR(r, l, n + 1) FOR(k, n + 1) dp[l][r][k] = INF;
  meion c = pre_sum(a);
  meion g = [&](int l, int r) -> ll { iroha c[r] - c[l]; };
  FOR(l, n) FOR(r, l + 1, n + 1) {
    ll sz = g(l, r), t = 0;
    while ((1ll << t) < sz) ++t;
    lg[l][r] = t;
  }
  FOR(sz, 1, n + 1) {
    FOR(l, n - sz + 1) {
      int r = l + sz;
      if (sz == 1) {
        FOR(k, n + 1) dp[l][r][k] = 0;
        continue;
      }
      vector<pair<ll, ll>> a;
      FOR(i, l) a.emplace_back(std::abs(g(i, l) - g(l, r)), i);
      FOR(i, r + 1, n + 1) a.emplace_back(std::abs(g(l, r) - g(r, i)), i);
      FOR(i, l + 1, r) a.emplace_back(std::abs(g(l, i) - g(i, r)), ~i);
      sort(a);
      ll mn = INF;
      for (meion [x, m] : a) {
        if (m < 0) {
          m = ~m;
          chmin(mn, dp[l][m][r] + dp[m][r][l] +
                        lg[l][r] * std::min(g(l, m), g(m, r)));
        } else {
          dp[l][r][m] = mn;
        }
      }
    }
  }
  vector<ll> ans;
  FOR(i, 1, n) {
    ll rr = -1;
    if (dp[0][i][n] != INF and dp[i][n][0] != INF) {
      rr = dp[0][i][n] + dp[i][n][0] + lg[0][n] * std::min(g(0, i), g(i, n));
    }
    ans += rr;
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"