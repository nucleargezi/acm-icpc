#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/sl/cht.hpp"

void Yorisou() {
  INT(N, Q);
  cht<ll, 0> f;
  FOR(N) {
    LL(a, b);
    f.add(a, b);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      LL(a, b);
      f.add(a, b);
    } else {
      LL(x);
      print(f(x));
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"