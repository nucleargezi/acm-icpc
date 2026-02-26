#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, M);
  vc<mint> dp(N + 1), ndp(dp);
  dp[0] = 1;
  FOR(i, 1, M + 1) {
    fill(all(ndp), 0);
    FOR(t, i + 1) FOR(i, N - t + 1) ndp[i + t] += dp[i] * C<mint>(N - i, t);
    swap(dp, ndp);
  }
  print(dp[N]);
}
#include "YRS/aa/main.hpp"