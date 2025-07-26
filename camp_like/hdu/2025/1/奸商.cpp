#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  S(s);
  FOR(i, n) s[i] -= 'a';
  static constexpr int N = 17, M = 1 << N;
  VEC(ll, w, N);
  LL(L);
  vector<u8> vis(M);
  FOR(i, n - 1) {
    int l = i, r = i + 1;
    if (s[l] == s[r]) continue;
    int msk = 1 << std::min(s[l], s[r]), le = 2;
    if (le >= L) vis[msk] = 1;
    while (l > 0 and r + 1 < n) {
      --l, ++r, le += 2;
      if (s[l] == s[r]) break;
      msk |= 1 << std::min(s[l], s[r]);
      if (le >= L) vis[msk] = 1;
    }
  }

  bool ok = 1;
  for (int i = 1; i < (M) and ok; ++i) {
    if (vis[i]) ok = 0;
  }
  if (ok) iroha UL(0);

  vector<u8> go(M);
  FOR(msk, 1, M) {
    if (vis[msk]) {
      int set = msk ^ (M - 1);
      FOR_subset(x, set) {
        go[x] = 1;
      }
    }
  }
  vector<int> dp(M);
  FOR(msk, 1, M) {
    dp[msk] = dp[msk ^ (1 << lowbit(msk))] + w[lowbit(msk)];
  }
  ll ans = inf<ll>;
  FOR(msk, M) if (not go[msk]) chmin(ans, dp[msk]);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"