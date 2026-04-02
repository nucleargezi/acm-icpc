#include "YRS/all.hpp"

void Yorisou() {
  INT(C, N);
  VEC(int, a, N);
  vc<int> dp(C + 1, inf<int>);
  dp[0] = 0;
  for (int x : a) {
    FOR(i, x, C + 1) if (dp[i - x] != inf<int>) {
      chmin(dp[i], dp[i - x] + 1); 
    }
  }
  print(dp[C] == inf<int> ? -1 : dp[C]);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"