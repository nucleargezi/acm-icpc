#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/run_length.hpp"

#define tests
void Yorisou() {
  LL(n);
  SV(s, '0');
  meion seg = run_length(s);
  ll dp[3]{};
  for (int s = 0; meion [x, y] : seg) {
    if (x == 1) {
      std::tie(dp[0], dp[1], dp[2]) =
          tuple(dp[0] + y, MIN(dp[0], dp[1]), MIN(dp[0], dp[1], dp[2]) + y);
    } else {
      std::tie(dp[0], dp[1], dp[2]) =
          tuple(dp[0], MIN(dp[0], dp[1]) + y, MIN(dp[0], dp[1], dp[2]));
    }
  }
  UL(MIN(dp[0], dp[1], dp[2]));
}
#include "MeIoN_Lib/Z_H/main.hpp"