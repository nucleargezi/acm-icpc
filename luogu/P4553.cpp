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
  VEC(int, a, N);
  int s = N + N, ss = s + 1, t = s + 2;
  mcf g(t + 1);
  g.add(s, ss, M, 0);
  FOR(i, N) {
    g.add(s, i, a[i], 0);
    g.add(i + N, t, a[i], 0);
    g.add(ss, i + N, inf<int>, 0);
  }
  FOR(i, N - 1) FOR(k, i + 1, N) {
    INT(x);
    if (x == -1) continue;
    g.add(i, k + N, inf<int>, x);
  }
  print(g.flow(s, t).se);
}
#include "YRS/aa/main.hpp"