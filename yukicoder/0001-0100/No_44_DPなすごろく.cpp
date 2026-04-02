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
  vc<ull> f(N + 2);
  f[0] = 1;
  FOR(i, N) f[i + 1] += f[i], f[i + 2] += f[i];
  print(f[N]);
}
#include "YRS/aa/main.hpp"