#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/treap/treap_monoid_commute.hpp"

#define tests 0
#define fl 0
#define DB 10
struct MX {
  using X = int;
  static constexpr X op(X l, X r) { return max(l, r); }
  static constexpr X unit() { return 0; }
};
using DS = treap_monoid_commute<MX>;
using np = DS::np;
void Yorisou() {
  INT(N);
  DS g;
  np t = nullptr;
  FOR(i, N) {
    INT(x);
    np m = g.newnode(i);
    Z [l, r] = g.split(t, x);
    g.set(m, 0, g.prod(l) + 1);
    t = g.merge(l, m, r);
    print(g.prod(t));
  }
}
#include "YRS/aa/main.hpp"