#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/sl/cht.hpp"

void Yorisou() {
  INT(N);
  cht<i128, 1> mx;
  cht<i128, 0> mn;
  vc<PLL> f;
  FOR(N) {
    LL(b, a);
    f.ep(b, a);
    mx.add(a, b);
    mn.add(a, b);
  }
  print(bina([&](ll x) {
    return mx(x) - mn(x) <= mx(x + 1) - mn(x + 1);
  }, inf<int>, 0));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"