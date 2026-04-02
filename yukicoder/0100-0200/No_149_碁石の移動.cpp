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
  INT(a, aa, b, bb, c, d);
  c -= min(c, aa);
  if (c) a -= c, b += c;
  print(a + min(b, d));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"