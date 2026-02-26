#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/line_inte.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  LL(N);
  array<array<mint, 2>, 2> dp{}, ndp{};
  dp[0][0] = 1;
  fps f;
  FOR(i, 4) {
    f.ep(dp[1][0]);
    FOR(i, 2) FOR(k, 2) ndp[i][k] = 0;
    FOR(i, 2) FOR(k, 2) {
      ndp[i][k] += dp[i][k];
      ndp[i][k ^ 1] += dp[i][k];
      ndp[i ^ 1][k] += dp[i][k];
    }
    dp.swap(ndp);
  }
  print(line_inte(f, N));
}
#include "YRS/aa/main.hpp"