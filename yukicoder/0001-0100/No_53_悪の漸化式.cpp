#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  using re = f128;
  INT(N);
  vc<re> f(N + 1);
  f[0] = 4, f[1] = 3;
  FOR(i, 2, N + 1) {
    f[i] = (19 * f[i - 1] - 12 * f[i - 2]) / 4;
  }
  setp(10);
  print(f[N]);
}
#include "YRS/aa/main.hpp"