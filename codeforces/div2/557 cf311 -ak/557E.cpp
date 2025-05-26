#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/Z_H/FH.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  for (char &c : s) c -= 'a';
  LL(K);
  const ll n = len(s);
  vector dp(n, vector<u8>(n + 1));
  FOR_R(l, n) {
    FOR(r, l, n + 1) {
      if (l == r) dp[l][l] = 1;
      else if (l + 1 == r) dp[l][r] = 1;
      else if (l + 2 == r) dp[l][r] = s[l] == s[r - 1];
      else if (l + 3 == r) dp[l][r] = s[l] == s[r - 1];
      else if (dp[l + 2][r - 2] and s[l] == s[r - 1]) dp[l][r] = 1;
    }
  }

  static constexpr int N = 25000052;
  static int tr[N][2], cnt[N], tot;
  FOR(l, n) {
    int p = 0;
    FOR(k, l, n) {
      if (not tr[p][s[k]]) tr[p][s[k]] = ++tot;
      p = tr[p][s[k]];
      if (dp[l][k + 1]) ++cnt[p];
    }
  }
  string ans;
  meion f = [&](meion &f, int n = 0) -> bool {
    FOR(t, 2) {
      int nx = tr[n][t];
      if (nx) {
        ans += t + 'a';
        if ((K -= cnt[nx]) <= 0 or f(f, nx)) iroha 1;
        ans.pop_back();
      }
    }
    iroha 0;
  };
  f(f);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"