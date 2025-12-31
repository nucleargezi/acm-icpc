#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/lag.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = modint<1'000'000'000 + 9>;
void Yorisou() {
  int N = 3000;
  vc<mint> dp(N);
  dp[0] = 1;
  for (int x : {1, 5, 10, 50, 100, 500}) {
    FOR(i, N - x) dp[i + x] += dp[i];
  }
  vc<array<mint, 6>> y(500);
  FOR(s, 500) FOR(i, 6) y[s][i] = dp[s + 500 * i];
  LL(Q);
  FOR(Q) {
    LL(x);
    int d = x % 500;
    x /= 500;
    print(lag_inte_iota<mint>(vc<mint>(y[d].begin(), y[d].end()), x));
  }
}
#include "YRS/aa/main.hpp"