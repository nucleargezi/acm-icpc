#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/g/bcc_e.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(M, N);
  retsu<int> a(N, M);
  IN(a);
  FOR(i, N) FOR(k, M) --a[i][k];

  graph g(N * M);
  Z f = [&](int i, int k) { return i * M + k; };
  FOR(i, N) FOR(k, M) {
    if (i and a[i][k] == a[i - 1][k]) g.add(f(i, k), f(i - 1, k));
    if (k and a[i][k] == a[i][k - 1]) g.add(f(i, k), f(i, k - 1));
  }
  g.build();
  Z [T, id] = bcc_e(g);
  vc<int> c(T);
  FOR(i, N * M) ++c[id[i]];
  possible(QMAX(c) > 1);
}
#include "YRS/aa/main.hpp"