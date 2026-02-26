#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
#include "YRS/pr/divisors.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  int s = 1;
  for (int x : divisor(N)) if (x != N) chmax(s, x);
  print(s);
}
#include "YRS/aa/main.hpp"