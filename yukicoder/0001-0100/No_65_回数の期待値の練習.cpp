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
  INT(K);
  vc<re> f(K + 1);
  FOR_R(i, K) FOR(k, 1, 7) f[i] += (f[min(K, i + k)] + 1) / 6;
  print(f[0]);
}
#include "YRS/aa/main.hpp"