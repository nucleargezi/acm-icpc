#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/sps/comp.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, 1 << N);
  VEC(mint, g, N + 1);
  print(sps_comp(g, f));
}
#include "YRS/aa/main.hpp"