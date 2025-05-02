#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, k);
  S(s);
  vector<ll> p[k];
  FOR(i, n) p[s[i] - 'a'] += i;
  vector<ll> dp(n, inf<ll>);
  FOR_R(i, n) {
    FOR(nxt, k) {
      meion it = upper(p[nxt], i);
      chmin(dp[i], it == p[nxt].end() ? 1 : dp[*it] + 1);
    }
  }
  LL(q);
  FOR(q) {
    S(s);
    ll t = -1;
    for (char c : s) {
      c -= 'a';
      meion it = upper(p[c], t);
      t = it == p[c].end() ? -1 : *it;
      if (t == -1) break;
    }
    UL(~t ? dp[t] : 0);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"