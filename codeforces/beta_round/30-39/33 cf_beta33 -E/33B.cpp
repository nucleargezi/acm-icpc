#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s, t);
  ll n = len(s);
  LL(m);
  ll dp[26][26];
  std::fill(dp[0], dp[0] + 26 * 26, inf<int>);
  FOR(i, 26) dp[i][i] = 0;
  FOR(m) {
    CH(a, b);
    LL(w);
    chmin(dp[a - 'a'][b - 'a'], w);
  }
  if (len(s) != len(t)) iroha UL(-1);
  FOR(i, 26) FOR(x, 26) FOR(y, 26) chmin(dp[x][y], dp[x][i] + dp[i][y]);
  ll cost = 0;
  string ans = s;
  FOR(i, n) if (s[i] != t[i]) {
    ll c = inf<int>;
    FOR(go, 26) {
      if (chmin(c, dp[s[i] - 'a'][go] + dp[t[i] - 'a'][go])) {
        ans[i] = go + 'a';
      }
    }
    if (c == inf<int>) iroha UL(-1);
    cost += c;
  }
  UL(cost);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"