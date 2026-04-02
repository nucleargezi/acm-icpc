#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M17;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<mint> c(100);
  for (int x : a) c[x - 1] += 1;
  mint s = 0;
  FOR(i, 100) FOR(k, i + 1, 100) FOR(j, k + 1, 100) s += c[i] * c[k] * c[j];
  print(s);
}
#include "YRS/aa/main.hpp"