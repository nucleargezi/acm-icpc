#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/treap/treap_monoid_commute.hpp"
#include "YRS/ds/monoid/add_array.hpp"

#define tests 0
#define fl 0
#define DB 10
using MX = monoid_add_array<ll, 200>;
using X = MX::X;
using DS = treap_monoid_commute<MX>;
using np = DS::np;
void Yorisou() {
  INT(N, M);
  vc<X> a(N, X{});
  FOR(i, N) {
    INT(sz);
    FOR(k, sz) {
      INT(x, y);
      a[i][x] = y;
    }
  }
  DS g;
  np t = g.newnode(a);
  vc<ll> out(M);
  INT(Q);
  FOR(Q) {
    STR(op);
    if (op == "I") {
      INT(x);
      X nx{};
      INT(sz);
      FOR(sz) {
        INT(x, y);
        nx[x] = y;
      }
      np mid = g.newnode(nx);
      Z [l, r] = g.split(t, x);
      t = g.merge(l, mid, r);
    } else if (op == "D") {
      INT(x);
      --x;
      Z [l, m, r] = g.split(t, x, x + 1);
      t = g.merge(l, r);
    } else if (op == "QA") {
      print(t->sz);
    } else {
      INT(l, r);
      --l;
      X s = g.prod(t, l, r);
      FOR(i, M) out[i] = s[i];
      print(out);
    }
  }
  print("end");
}
#include "YRS/aa/main.hpp"