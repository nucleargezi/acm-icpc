#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
#include "YRS/po/lag.hpp"
#include "YRS/aa/def.hpp"

using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, f ,N + 1);
  print(lag_inte_iota<mint>(f, M, N + 1));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"