#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/unionfind/dynamic_dsu.hpp"

#define tests 0
#define fl 0
#define DB 10
using DS = dynamic_dsu<1, 1 << 19>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  DS g;
  vc<np> t(Q + 1);
  t[0] = nullptr;
  FOR(i, 1, Q + 1) {
    INT(op);
    if (op == 1) {
      INT(x, y);
      --x, --y;
      t[i] = g.merge(t[i - 1], x, y).fi;
    } else if (op == 2) {
      INT(k);
      t[i] = t[k];
    } else {
      t[i] = t[i - 1];
      INT(x, y);
      --x, --y;
      print(g.same(t[i], x, y));
    }
  }
}
#include "YRS/aa/main.hpp"