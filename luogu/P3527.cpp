#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/fenw/dual_fenw.hpp"
#include "YRS/ds/monoid/add.hpp"

#define tests 0
#define fl 0
#define DB 10
using MX = monoid_add<ll>;
using BIT = dual_fenw<MX>;
void Yorisou() {
  INT(N, M);
  VEC(int, a, M);
  vc<vc<int>> v(N);
  FOR(i, M) v[--a[i]].ep(i);
  VEC(int, nd, N);
  INT(Q);
  VEC(T3<int>, q, Q);
  
  vc<vc<int>> qs(Q + 1);
  vc<PII> res(N, {Q, -1});
  BIT seg(M);
  while (1) {
    bool f = 0;
    FOR(i, Q) qs[i].clear();
    FOR(i, N) {
      Z [l, r] = res[i];
      if (abs(r - l) > 1) f = 1, qs[(l + r) >> 1].ep(i);
    }
    if (not f) break;
    seg.build(M);
    FOR(i, Q) {
      Z [l, r, w] = q[i];
      if (l <= r) seg.apply(l - 1, r, w);
      else seg.apply(0, r, w), seg.apply(l - 1, M, w);
      for (int id : qs[i]) {
        ll s = nd[id];
        for (int x : v[id]) if ((s -= seg.get(x)) <= 0) break;
        if (s <= 0) res[id].fi = i;
        else res[id].se = i;
      }
    }
  }
  for (Z [l, r] : res) {
    if (l == Q) NIE();
    else print(l + 1);
  }
}
#include "YRS/Z_H/main.hpp"