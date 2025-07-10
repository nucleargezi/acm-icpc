#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, mod);
  vector<ll> dp(n + 1);
  dp[0] = 1;
  for (ll i = n, g = 1; i > 0; --i, ++g) {
    FOR_R(x, g) {
      dp[x + 1] = (dp[x + 1] + dp[x] * i % mod * (n - i - x + 1) % mod) % mod;
    }
  }
  print("{}", SUM(dp) % mod);
}
#include "MeIoN_Lib/Z_H/main.hpp"