#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int x = 0, y = 0;
  FOR(i, N) (a[i] & 1 ? x : y) += 1;
  print(N - 2 * min(x, y));
}
#include "YRS/aa/main.hpp"