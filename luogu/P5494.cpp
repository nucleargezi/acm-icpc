#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/seg/dynamic_seg.hpp"
#include "YRS/ds/monoid/add.hpp"
#include "YRS/ds/seg/dynamic_seg.hpp"

#define tests 0
#define fl 0
#define DB 10
using MX = monoid_add<ll>;
using DS = dynamic_seg<MX, 0, int>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  DS seg(0, N);
  vc<np> rt(Q + 1);
  int t = 0;
  rt[t++] = seg.newnode(a);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(p, l, r);
      --p, --l;
      rt[t] = seg.spl(rt[t], rt[p], l, r);
      ++t;
    } else if (op == 1) {
      INT(t, f);
      --t, --f;
      rt[t] = seg.merge_to(rt[t], rt[f], MX::op);
    } else if (op == 2) {
      INT(p, x, q);
      --p, --q;
      rt[p] = seg.multiply(rt[p], q, x);
    } else if (op == 3) {
      INT(p, l, r);
      --p, --l;
      print(seg.prod(rt[p], l, r));
    } else {
      INT(p, K);
      --p;
      if (seg.prod(rt[p], 0, N) < K) print(-1);
      else print(seg.max_right(rt[p], [&](ll s)  { return s < K; }, 0) + 1);
    }
  }
}
#include "YRS/Z_H/main.hpp"