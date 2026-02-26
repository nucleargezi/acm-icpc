#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/unionfind/dsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  dsu g(1000);
  FOR(N) {
    INT(x, y);
    print(g[x] == g[y] ? "Y" : "N");
    g.merge(x, y);
  }
}
#include "YRS/aa/main.hpp"