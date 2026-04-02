#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/fenw/fenw.hpp"
#include "YRS/al/m/add.hpp"

#define tests 0
#define fl 0
#define DB 10
using MX = monoid_add<int>;
void Yorisou() {
  INT(N, K);
  constexpr int sz = 1'000'001;
  fenw<MX> bit(sz);
  FOR(N) {
    INT(w);
    if (w > 0) {
      if (bit.prod(w, sz) < K) bit.multiply(w, 1);
    } else {
      w = -w;
      if (bit.prod(w, w + 1)) bit.multiply(w, -1);
    }
  }
  print(bit.prod_all());
}
#include "YRS/aa/main.hpp"