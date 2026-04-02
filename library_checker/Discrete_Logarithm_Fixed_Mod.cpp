#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/mod/log_table.hpp"
#include "YRS/mod/modfast_d.hpp"

void Yorisou() {
  INT(mod, g, Q);
  if (mod <= 1'000'000) {
    vc<int> t = log_table(mod, g);
    FOR(Q) {
      INT(x);
      print(t[x]);
    }
    return;
  }
  modfast_d X(mod, g);
  FOR(Q) {
    INT(x);
    print(X.log_r(x));
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"