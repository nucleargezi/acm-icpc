#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/treap/treap_act.hpp"
#include "YRS/ds/a_monoid/min_add.hpp"

#define tests 0
#define fl 0
#define DB 10
using AM = a_monoid_min_add<int>;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  treap_act<AM> seg;
  INT(M);
  Z t = seg.newnode(a);
  FOR(M) {
    STR(op);
    if (op == "ADD") {
      INT(l, r, x);
      --l;
      t = seg.apply(t, l, r, x);
    } else if (op == "REVERSE") {
      INT(l, r);
      --l;
      t = seg.reverse(t, l, r);
    } else if (op == "REVOLVE") {
      INT(l, r, x);
      --l;
      x %= r - l;
      if (x == 0) continue;
      t = seg.reverse(t, l, r);
      t = seg.reverse(t, l, l + x);
      t = seg.reverse(t, l + x, r);
    } else if (op == "INSERT") {
      INT(x, w);
      Z [a, b] = seg.split(t, x);
      Z np = seg.newnode(w);
      t = seg.merge(a, np, b);
    } else if (op == "DELETE") {
      INT(x);
      --x;
      Z [a, mid, b] = seg.split(t, x, x + 1);
      t = seg.merge(a, b);
    } else if (op == "MIN") {
      INT(l, r);
      --l;
      print(seg.prod(t, l, r));
    }
  }
}
#include "YRS/Z_H/main.hpp"