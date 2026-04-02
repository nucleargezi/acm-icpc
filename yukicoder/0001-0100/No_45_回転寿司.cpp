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
  vc<array<int, 2>> f(N);
  f[0][1] = a[0];
  FOR(i, 1, N) {
    f[i][0] = max(f[i - 1][0], f[i - 1][1]);
    f[i][1] = f[i - 1][0] + a[i];
  }
  print(QMAX(f[N - 1]));
}
#include "YRS/aa/main.hpp"