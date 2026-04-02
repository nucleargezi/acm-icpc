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
  FOR(m, 1, N + 1) {
    mint t, o = 1;
    FOR(i, m + 1) t += o * CC(m, i) * (mint(m) * m - i).pow(N), o = -o;
    s += t / fac(m);
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"