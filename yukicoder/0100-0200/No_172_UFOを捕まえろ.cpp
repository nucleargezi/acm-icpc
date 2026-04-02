#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

void Yorisou() {
  INT(x, y, r);
  print(abs(x) + abs(y) + (int)ceil(r * sqrtl(2)));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"