#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/sl/cht.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(ll, h, N);
  VEC(ll, w, N);
  FOR(i, 1, N) w[i] += w[i - 1];
  cht<ll, 0> f;
  vc<ll> dp(N);
  f.add(-2 * h[0], h[0] * h[0] - w[0]);
  FOR(i, 1, N) {
    dp[i] = f(h[i]) + h[i] * h[i] + w[i - 1];
    f.add(-2 * h[i], h[i] * h[i] - w[i] + dp[i]);
  }
  print(dp[N - 1]);
}
#include "YRS/aa/main.hpp"