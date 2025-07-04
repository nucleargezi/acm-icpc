#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M17;
void Yorisou() {
  int t = 0;
  int n, m;
  while (std::cin >> n >> m) {
    const int N = n * m, M = 1 << N;
    vector<int> a(N), msks;
    FOR(i, n * m) IN(a[i]);
    const int H = QMAX(a);
    FOR(k, 1, H + 1) {
      int msk = 0;
      FOR(i, N) {
        if (a[i] >= k) msk |= 1 << i;
      }
      msks.emplace_back(msk);
    }
    msks.emplace_back(0);
    vector<int> v(N);
    FOR(i, n) FOR(k, m) {
      int x = i * m + k;
      if (i) v[x] |= 1 << (i * m - m + k);
      if (i + 1 < n) v[x] |= 1 << (i * m + m + k);
      if (k) v[x] |= 1 << (i * m + k - 1);
      if (k + 1 < m) v[x] |= 1 << (i * m + k + 1);
    }
    vector<mint> f(M), ff(M);
    f[0] = ff[0] = 1;
    FOR(msk, 1, M) {
      int x = lowbit(msk), t = msk ^ (1 << x);
      f[msk] = f[t];
      FOR(i, N) if ((t & v[x]) >> i & 1) {
        f[msk] += f[t ^ (1 << i)];
        ff[msk] += ff[t ^ (1 << i)];
      }
    }
    vector<mint> dp(M), dpp(M);
    dp[0] = dpp[0] = 1;
    meion go = [&](meion &dp, meion &f) {
      FOR(i, H) {
        vector<mint> ndp(M);
        FOR(msk, M) {
          if ((msk & ~msks[i]) or not dp[msk].val) continue;
          int s = msks[i + 1] & ~msk, m = msks[i] & ~msk;
          FOR_subset(set, s) {
            ndp[set] += dp[msk] * f[m & ~set];
          }
        }
        dp.swap(ndp);
      }
    };
    go(dp, f), go(dpp, ff);
    UL(std::format("Case {}: {} {}", ++t, (dp[0] - dpp[0]).val, dpp[0].val));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"