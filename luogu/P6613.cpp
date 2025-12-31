#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/fps_ode_exp.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, a, N + 1);
  VEC(mint, b, N + 1);
  print(fps_ode_exp(a, b));
}
#include "YRS/aa/main.hpp"