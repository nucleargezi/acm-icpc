#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/treap/treap_act.hpp"
#include "YRS/ds/a_monoid/max_add.hpp"

#define tests 0
#define fl 0
#define DB 10
using AM = a_monoid_max_add<ll>;
using DS = treap_act<AM>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  DS seg;
  np s = seg.newnode(vc<ll>(N));
  FOR(Q) {
    INT(op);
    err(op);
    if (op == 1) {
      INT(l, r, x);
      --l;
      s = seg.apply(s, l, r, x);
    } else if (op == 2) {
      INT(l, r);
      --l;
      s = seg.reverse(s, l, r);
    } else {
      INT(l, r);
      --l;
      print(seg.prod(s, l, r));
    }
  }
}
#include "YRS/aa/main.hpp"