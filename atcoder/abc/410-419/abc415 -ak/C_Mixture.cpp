#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  const int N = 1 << n;
  SV(s, '0');
  vector<u8> dp(N);
  FOR(i, n) if (not s[(1 << i) - 1]) dp[1 << i] = 1;
  FOR(i, N) if (dp[i]) {
    FOR(k, n) {
      if (i >> k & 1) continue;
      if (s[(1 << k | i) - 1]) continue;
      dp[1 << k | i] = 1;
    }
  }
  Yes(dp[N - 1]);
}
#include "MeIoN_Lib/Z_H/main.hpp"