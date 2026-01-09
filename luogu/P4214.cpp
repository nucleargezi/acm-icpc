#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"
#include "YRS/g/bcc_e.hpp"
#include "YRS/ds/unionfind/dsu.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/modint61.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  VEC(PII, e, M);
  dsu f(N);
  graph g(N);
  for (Z &[x, y] : e) --x, --y, g.add(x, y), f.merge(x, y);
  g.build();
  retsu<int> a(N, N, -1);

  FOR(i, N) FOR(k, i + 1, N) if (f[i] != f[k]) a[i][k] = 0;

  Z [c, id] = bcc_e(g);
  FOR(i, N) FOR(k, i + 1, N) if (a[i][k] == -1 and id[i] != id[k]) a[i][k] = 1;
  vc<M61> bs(N), h(N);
  FOR(i, N) bs[i] = rng_64();
  FOR(i, N) h[i] = bs[id[i]];
  M61 B = rng_64();

  FOR(i, M) {
    graph ng(N);
    FOR(k, M) if (i != k) {
      ng.add(e[k].fi, e[k].se);
    }
    ng.build();
    Z [c, v] = bcc_e(ng);
    FOR(i, N) h[i] = h[i] * B + bs[v[i]];
  }
  FOR(i, N) FOR(k, i + 1, N) if (a[i][k] == -1) {
    if (h[i] != h[k]) a[i][k] = 2;
    else a[i][k] = 3;
  }
  int s = 0;
  FOR(i, N) FOR(k, i + 1, N) s += a[i][k];
  print(s);
}
#include "YRS/aa/main.hpp"