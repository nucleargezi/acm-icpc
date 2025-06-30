#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, K);
  VEC(ll, p, n);
  VEC(ll, d, n);
  map<ll, vector<int>> mr, ml;
  map<ll, vector<ll>> mvr;
  FOR(i, n) {
    mr[((p[i] - d[i]) % K + K) % K].emplace_back(i);
    mvr[((p[i] - d[i]) % K + K) % K].emplace_back(p[i]);
  }
  vector<int> L(n + 1, n), R(n + 1, n);
  for (meion &[x, v] : mr) {
    v.emplace_back(n);
    mvr[x].emplace_back(inf<ll>);
    int n = len(v) - 1;
    FOR(i, n) {
      R[v[i]] = v[i + 1];
    }
  }
  FOR_R(i, n) {
    ml[(p[i] + d[i]) % K].emplace_back(i);
  }
  for (meion &[x, v] : ml) {
    v.emplace_back(n);
    int n = len(v) - 1;
    FOR(i, n) {
      L[v[i]] = v[i + 1];
    }
  }
  vector<int> dp(n + 1), ndp(n + 1);
  FOR(i, n + 1) dp[i] = L[R[i]];
  FOR(i, 1, 22) {
    FOR(k, n + 1) {
      ndp[k] = dp[dp[k]];
    }
    dp.swap(ndp);
  }
  LL(q);
  FOR(q) {
    LL(x);
    if (mvr.contains(x % K)) {
      int i = lower_bound(mvr[x % K], x) - 1;
      x = i > -1 ? mr[x % K][i] : n;
    } else {
      x = n;
    }
    YES(dp[x] == n);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"