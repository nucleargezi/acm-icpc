#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/chirp_z.hpp"

#define tests 0
#define fl 0
#define DB 1000
using mint = M17;
void Yorisou() {
  INT(n, c, m);
  VEC(mint, f, n);
  print(chirp_z_transform<mint>(f, c, m));
}
#include "YRS/aa/main.hpp"