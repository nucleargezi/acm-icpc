#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/basic/hashmap.hpp"

void Yorisou() {
  INT(Q);
  hashmap<ll> a(Q);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      LL(x, y);
      a[x] = y;
    } else {
      LL(x);
      print(a.get(x, 0));
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"