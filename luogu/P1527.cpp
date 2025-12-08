#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/fenw/fenwfenw.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, Q);
  retsu<int> a(N, N);
  FOR(i, N) FOR(k, N) IN(a[i][k]);
  vc<int> f = a.A;
  unique(f);
  int sz = len(f);
  vc<vc<PII>> v(sz);
  FOR(i, N) FOR(k, N) v[lb(f, a[i][k])].ep(i, k);
  using dat = struct {
    int x, y, xx, yy, K, l, r;
  };
  vc<dat> q(Q);
  FOR(i, Q) {
    INT(x, y, xx, yy, K);
    --x, --y;
    q[i] = {x, y, xx, yy, K, sz - 1, -1};
  }
  vc<int> X(N * N), Y(N * N);
  FOR(i, N) FOR(k, N) X[i * N + k] = i, Y[i * N + k] = k;
  fenwfenw<monoid_add<int>> bit(N, N);
  vc<vc<int>> qs(sz + 1);
  while (1) {
    bool f = 0;
    FOR(i, sz) qs[i].clear();
    FOR(i, Q) {
      int l = q[i].l, r = q[i].r;
      if (abs(r - l) > 1) f = 1, qs[(l + r) >> 1].ep(i);
    }
    if (not f) break;
    bit.reset();
    FOR(i, sz) {
      for (Z [x, y] : v[i]) bit.multiply(x, y, 1);
      for (int id : qs[i]) {
        Z &[l, u, r, d, K, ql, qr] = q[id];
        if (bit.prod(l, r, u, d) >= K) ql = i;
        else qr = i;
      }
    }
  }
  FOR(i, Q) print(f[q[i].l]);
}
#include "YRS/Z_H/main.hpp"