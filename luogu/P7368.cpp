#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/flow/BM.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  graph g(N << 1);
  FOR(M) {
    INT(x, y);
    --x, --y;
    g.add(x, y + N);
  }
  g.build();
  B_matching f(g);
  print(len(f.vcov()));
}
#include "YRS/aa/main.hpp"