#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/flow/mcf.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  int s = N + 2, t = s + 1;
  mcf FL(t + 1);
  VEC(int, a, N);
  FOR(i, N) FL.add(i, i + 1, inf<int> - a[i], 0);
  FL.add(s, 0, inf<int>, 0);
  FL.add(N, t, inf<int>, 0);
  FOR(M) {
    INT(l, r, w);
    --l;
    FL.add(l, r, inf<int>, w);
  }
  print(FL.flow(s, t).se);
}
#include "YRS/Z_H/main.hpp"