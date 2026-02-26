#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/seq/inversion.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  FOR(i, N) --a[i];
  vc<int> b(N);
  iota(all(b), 0);
  print(inversion_between(a, b));
}
#include "YRS/aa/main.hpp"