#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/tr/nearr.hpp"

void Yorisou() {
  INT(N);
  VEC(T3<int>, es, N - 1);
  graph g(N);
  for (Z &[x, y, w] : es) {
    --x, --y;
    g.add(x, y, w);
  }
  g.build();
  nearr<int, ll, ll> ds(g);
  
  INT(Q);
  vc<PII> q(Q);
  FOR(i, Q) {
    CH(op);
    if (op == '+') {
      INT(x, r);
      q[i] = {x, r};
      ds.addpos(x - 1, r);
    } else {
      INT(x);
      q[i] = {-x, 0};
    }
  }
  ds.build();
  for (Z [x, r] : q) {
    if (x < 0) {
      x = -x - 1;
      Z [f, t, w] = es[x];
      print(ds.prod(f, t, w));
    } else {
      --x;
      ds.add(x, r, 1);
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"