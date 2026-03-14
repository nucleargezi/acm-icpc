#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/g/mst_kru.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc<1, 0>(M);
  Z [s, es] = mst_kru(g);
  print(s);
  print(es);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"