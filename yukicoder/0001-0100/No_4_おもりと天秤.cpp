#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/basic/bit_vec.hpp"

// #define tests
using bs = bit_vec;
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  ll s = SUM(a);
  if (s & 1) iroha impossible();
  s >>= 1;
  bs dp(s + 1);
  dp[0] = 1;
  FOR(i, n) dp |= dp << a[i];
  possible(dp[s]);
}
#include "MeIoN_Lib/Z_H/main.hpp"