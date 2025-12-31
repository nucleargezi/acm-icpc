#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/fps_pow.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  LL(N, k);
  VEC(mint, f, N);
  print(fps_pow(f, k));
}
#include "YRS/aa/main.hpp"