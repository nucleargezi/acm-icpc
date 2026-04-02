#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
using RE = long double;
void Yorisou() {
  LL(n, K);
  REA(r0, c0, p, L, R);
  vector<RE> r(n + 1, L), c(n + 1);
  FOR(K) {
    LL(p);
    REA(x);
    r[p] = x;
  }
  r[0] = r0, c[0] = c0;
  RE dp[n + 1]{};
  FOR(i, 1, n + 1) {
    c[i] = p * c[i - 1] + (1 - p) * (r[i - 1]);
    dp[i] = dp[i - 1] + c[i] - r[i];
  }
  UL(dp[n]);
}
#include "MeIoN_Lib/Z_H/main.hpp"