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
  T a, b;
  IN(a, b);
  print(a.gcd(b));
}
#include "YRS/Z_H/main.hpp"