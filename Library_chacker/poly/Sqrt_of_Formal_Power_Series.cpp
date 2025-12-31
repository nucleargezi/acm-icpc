#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/fps_sqrt.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, N);
  f = fps_sqrt(f);
  if (len(f) != N) print(-1);
  else print(f);
}
#include "YRS/aa/main.hpp"