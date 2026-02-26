#define YRSD
#include "YRS/all.hpp"
// #include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/kmp.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  int N = len(s);
  vc<int> nx = get_next(s).fi, dp(N + 1), f(N + 1);
  dp[1] = f[1] = 1;
  FOR(i, 2, N + 1) {
    dp[i] = i;
    int k = nx[i];
    if (k > 0 and f[dp[k]] >= i - k) dp[i] = dp[k];
    f[dp[i]] = i;
  }
  print(dp[N]);
}
#include "YRS/aa/main.hpp"