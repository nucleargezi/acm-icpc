#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  LL(n, t, m, K);
  vector<vector<int>> v;
  vector<int> c;
  meion f = [&](meion &f, ll s) -> void {
    if (not s) iroha v += c;
    FOR(i, 1, s + 1) {
      if (not c.empty() and c.back() < i) break;
      c += i;
      f(f, s - i);
      c.pop_back();
    }
  };
  f(f, m);
  RE dp[t + 1][K + 1]{};
  dp[0][0] = 1;
  FOR(i, t) { 
    FOR(k, K + 1) {
      for (meion &v : v) {
        RE s = 0;
        FOR(j, len(v)) {
          if (j > n - 1) break;
          s += dp[i][MAX(0ll, k - v[j])];
        }
        if (len(v) < n) s += dp[i][k] * (n - len(v));
        chmax(dp[i + 1][k], s / n);
      }
    }
  }
  UL(dp[t][K]);
}
#include "MeIoN_Lib/Z_H/main.hpp"