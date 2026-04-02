#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
void Yorisou() {
  S(str);
  const int n = len(str);
  vector<ll> s(n);
  string O{"aehn"};
  FOR(i, n) s[i] = upper_bound(O, str[i]);
  ll ans = 0;
  constexpr int N = 20;
  FOR(N) {
    std::rotate(s.begin(), s.begin() + 1, s.end());
    vector<ll> dp(n + 1);
    FOR(i, n) {
      mint go;
      FOR(r, i, i + N) {
        if (r + 1 > n) break;
        go *= 31;
        go += s[r];
        chmax(dp[r + 1], dp[i] + go.val);
      }
    }
    chmax(ans, dp[n]);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"