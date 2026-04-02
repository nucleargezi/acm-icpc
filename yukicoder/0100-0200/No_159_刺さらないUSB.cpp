#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

using re = ld;
void Yorisou() {
  REAL(p, q);
  YES((1 - p) < p * (1 - q));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"