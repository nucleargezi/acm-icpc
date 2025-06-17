#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/primtable.hpp"

// #define tests
constexpr int N = 1'000'0;
vector prim = primtable(N);
vector vis = []() {
  vector<u8> vis(N + 1);
  for (int x : prim) vis[x] = 1;
  iroha vis;
}();
void Yorisou() {
  LL(n);
  vector<u8> dp(n + 1);
  dp[0] = dp[1] = 1;
  FOR(i, 2, n + 1) {
    for (int x : prim) {
      if (x >= i) break;
      if (dp[i - x]) continue;
      dp[i] = 1;
      break;
    }
  }
  UL(dp[n] ? "Win" : "Lose");
}
#include "MeIoN_Lib/Z_H/main.hpp"