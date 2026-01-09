#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/treap/treap_base.hpp"

#define tests 0
#define fl 0
#define DB 10
using DS = treap_base<int>;
using np = DS::np;
void Yorisou() {
  INT(N);
  vc<int> a(N);
  iota(all(a), 1);
  DS g;
  np t = g.newnode(a);
  FOR(i, N) {
    INT(x);
    x %= (N - i);
    Z [l, m, r] = g.split(t, x, x + 1);
    print(m->mx);
    t = g.merge(r, l);
  }
}
#include "YRS/aa/main.hpp"