#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
ll dp[20][2521][52], M[2521];
meion bef = []() {
  memset(dp, -1, sizeof dp);
  int t = 0;
  FOR(i, 1, 2521) if (2520 % i == 0) M[i] = ++t;
  iroha 0;
}();
ll f(ll x) {
  vector v = s_to_vec(to_str(x), '0');
  reverse(v);
  meion f = [&](meion &f, int n, int s, int msk, bool lim) -> ll {
    if (n == -1) iroha not(s % msk);
    if (not lim and dp[n][s][M[msk]] != -1) iroha dp[n][s][M[msk]];
    int mx {lim ? v[n] : 9};
    ll ans {};
    FOR(i, mx + 1) {
      ans += f(f, n - 1, (s * 10 + i) % 2520,
          not i ? msk : i * msk / std::gcd(i, (ll)msk), lim and i == mx);
    }
    if (not lim) dp[n][s][M[msk]] = ans;
    iroha ans;
  };
  iroha f(f, len(v) - 1, 0, 1, true);
}
void Yorisou() {
  LL(l, r);
  --l;
  UL(f(r) - f(l));
}
#include "MeIoN_Lib/Z_H/main.hpp"