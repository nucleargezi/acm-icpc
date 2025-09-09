#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void test(ll n, ll m) {
  VEC(ll, a, n);
  vector<int> e(n);
  FOR(m) {
    LL(x, y);
    --x, --y;
    e[x] |= 1 << y;
    e[y] |= 1 << x;
  }
  sort(a);
  const int N = 1 << n;
  vector<ll> dp(N, inf<ll>);
  dp[0] = 0;
  FOR(msk, 0, N) FOR(i, n) {
    if (msk >> i & 1) continue;
    int t = 1 << i | msk, c = popcount(msk);
    chmin(dp[t],
        dp[msk] + popcount(e[i] & t) * a[c] - popcount(e[i] & (~t)) * a[c]);
  }
  UL(dp[N - 1]);
}
void Yorisou() {
  ll n, m;
  while (IN(n, m)) {
    test(n, m);
  }
}
#include "YRS/Z_H/main.hpp"