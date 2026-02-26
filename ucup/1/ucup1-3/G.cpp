#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
using re = ld;
void Yorisou() {
  setp(10);
  INT(N, v);
  vc<PLL> a, b;
  FOR(N) {
    LL(x, v);
    (x < 0 ? a : b).ep(x, v);
  }
  print(v * bina_real<re>([&](re t) -> bool {
    re l = inf<re>, r = -l;
    for (Z [x, y] : a) chmax(r, x + y * t);
    for (Z [x, y] : b) chmin(l, x - y * t);
    return l <= r;
  }, 2'000'000'000'010, 0));
}
#include "YRS/aa/main.hpp"