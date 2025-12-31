#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/treap/treap_monoid.hpp"
#include "YRS/ds/monoid/min.hpp"

#define tests 0
#define fl 0
#define DB 10
using MX = monoid_min<PII>;
using DS = treap_monoid<MX>;
using np = DS::np;
void Yorisou() {
  INT(N);
  vc<PII> a(N);
  FOR(i, N) {
    INT(x);
    a[i] = {x, i};
  }
  DS seg;
  np t = seg.newnode(a);
  vc<int> ans;
  FOR(i, N) {
    Z x = seg.prod(t);
    Z [l, r] = seg.split_max_right(t, [&](PII e) { return e != x; });
    int sz = l ? l->sz : 0;
    ans.ep(sz + i + 1);
    Z [m, rr] = seg.split(r, 1);
    if (sz) l = seg.reverse(l, 0, sz);
    t = seg.merge(l, rr);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"