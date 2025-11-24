#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(N, M, K);
  VEC(int, a, N);
  if (~N & 1) return print(0);
  if (M < (N + 1) / 2) return print(0);
  ll mn = inf<ll>;
  FOR(i, 0, N, 2) chmin(mn, a[i]);
  print(min(M / ((N + 1) / 2) * K, mn));
}
#include "YRS/Z_H/main.hpp"