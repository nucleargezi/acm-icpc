#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/graph/Tree/near_kinbo.hpp"
#include "YRS/ds/fenw/fenw.hpp"
#include "YRS/ds/monoid/add.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  graph g(N);
  FOR(N - 1) {
    INT(x, y);
    g.add(x, y);
  }
  g.build();
  near_kinbo seg(g);
  vector<ll> s(len(seg));
  FOR(i, N) for (int x : seg.vs(i)) s[x] += a[i];
  fenw<monoid_add<ll>> bit(s);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y);
      for (int i : seg.vs(x)) bit.multiply(i, y);
    } else {
      INT(x, l, r);
      ll s = 0;
      for (Z [l, r] : seg.range(x, l, r)) s += bit.prod(l, r);
      print(s);
    }
  }
}
#include "YRS/Z_H/main.hpp"