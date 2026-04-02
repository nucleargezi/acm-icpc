#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  int ans = N / (2 * K) * K;
  N %= 2 * K;
  if (not N) N += 2 * K, ans -= K;
  print(ans);
}
#include "YRS/aa/main.hpp"