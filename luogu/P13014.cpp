#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/bigint/big.hpp"

#define tests 0
#define fl 0
#define DB 10
using T = bigint;
void Yorisou() {
  INT(N, Q);
  VEC(T, a, N);
  unique(a);
  N = len(a);
  T g = 0;
  FOR(i, 1, N) g = g.gcd(a[i] - a[i - 1]);
  FOR(i, 1, Q + 1) print(g.gcd(a[0] + i));
}
#include "YRS/Z_H/main.hpp"