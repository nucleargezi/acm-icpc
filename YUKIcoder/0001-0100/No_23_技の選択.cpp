#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = double;
void Yorisou() {
  INT(H, A, D);
  vc<re> f(H + 1, inf<re>);
  f[0] = 0;
  FOR(i, H) if (f[i] != inf<re>) {
    chmin(f[min(i + A, H)], f[i] + 1);
    chmin(f[min(i + D, H)], f[i] + re(3) / 2);
  }
  print(f[H]);
}
#include "YRS/aa/main.hpp"