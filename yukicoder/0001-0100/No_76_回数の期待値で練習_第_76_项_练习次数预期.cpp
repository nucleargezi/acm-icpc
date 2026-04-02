#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
using re = ld;
void Yorisou() {
  INT(K);
  vc<re> f(K + 1);
  re p[7];
  p[1] = 1.l / 12;
  p[2] = 2.l / 12;
  p[3] = 3.l / 12;
  p[4] = 1.l / 12;
  p[5] = 3.l / 12;
  p[6] = 2.l / 12;
  FOR_R(i, K) FOR(k, 1, 7) f[i] += (f[min(K, i + k)] + 1) * p[k];
  setp(16);
  print(f[0]);
}
#include "YRS/aa/main.hpp"