#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/mint.hpp"

using mint = M17;
void Yorisou() {
  INT(N);
  mint s;
  FOR(N) {
    LL(a, b);
    s += mint(ceil<ll>(a, 2)) * b;
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"