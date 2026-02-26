#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/dynamic_seg.hpp"
#include "YRS/ds/monoid/add.hpp"
#include "YRS/ds/lct/lct_base.hpp"
#include "YRS/ds/unionfind/dsu.hpp"

#define tests 0
#define fl 0
#define DB 10
using Seg = dynamic_seg<monoid_add<int>, true>;
using np = Seg::np;
using LCT = LCT_base;
void Yorisou() {
  INT(T, N, M, Q);
  VEC(int, a, N);
  vc<int> u(a);
  unique(u);
  int sz = len(u);
  for (int &x : a) x = lb(u, x);

  dsu g(N);
  vvc<int> v(N);
  LCT lct(N + 1);
  FOR(M) {
    INT(x, y);
    --x, --y;
    v[x].ep(y);
    v[y].ep(x);
    g.merge(x, y);
  }
  
  bool st = 1;
  Seg seg(0, N);
  vc<np> t(N, nullptr);
  Z f = [&](Z &f, int n, int an) -> void {
    if (an == -1) t[n] = seg.set(t[n], a[n], 1);
    else t[n] = seg.multiply(t[an], a[n], 1);
    for (int x : v[n]) if (x != an) {
      if (st) lct.link(x, n); 
      f(f, x, n);
    }
  };
  FOR(i, N) if (t[i] == nullptr) lct.link(i, N), f(f, i, -1);
  st = 0;

  int ans = 0;
  FOR(Q) {
    CH(op);
    if (op == 'Q') {
      INT(x, y, k);
      x ^= ans, y ^= ans, k ^= ans;
      --x, --y;
      lct.evert(N);
      int fa = lct.lca(x, y);
      lct.evert(N);
      if (fa == N) exit(0);
      int ffa = lct.get_fa(fa);
      print(ans = u[bina([&](int w) -> bool {
        return seg.prod(t[x], 0, w) + 
               seg.prod(t[y], 0, w) - 
               seg.prod(t[fa], 0, w) - 
               (ffa == N ? 0 : seg.prod(t[ffa], 0, w)) < k;
      }, 0, sz)]);
    } else {
      INT(x, y);
      x ^= ans, y ^= ans;
      --x, --y;
      if (g.size(y) > g.size(x)) swap(x, y);
      lct.evert(y);
      lct.cut(N, lct.get_fa(N));
      lct.link(x, y);
      f(f, y, x);
      v[x].ep(y);
      v[y].ep(x);
      g.merge(x, y);
    }
  }
}
#include "YRS/aa/main.hpp"