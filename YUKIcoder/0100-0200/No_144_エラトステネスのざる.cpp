#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

using re = double;
void Yorisou() {
  INT(N);
  REAL(p);
  p = 1 - p;
  re s = 0;
  vc<re> f(N + 1, 1);
  FOR(i, 2, N + 1) {
    s += f[i];
    FOR(k, i + i, N + 1, i) f[k] *= p;
  }
  setp(10);
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"