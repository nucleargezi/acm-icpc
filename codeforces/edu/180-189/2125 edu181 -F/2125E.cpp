#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

#define tests
using mint = M99;
void Yorisou() {
  LL(n, x);
  if (n == 1) iroha UL(x);
  ll lm = (n - 1) * (n + 2) / 2;
  if (x < lm) iroha UL(0);
  const int N = x - lm + 1;
  vector<mint> dp(x);
  FOR(i, lm - 1, x) dp[i] = 1;
  FOR(i, 1, n) FOR(k, x - i) dp[i + k] += dp[k];
  UL(SUM<mint>(dp));
}
#include "MeIoN_Lib/Z_H/main.hpp"