#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu_w.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, q);
  dsu_w<monoid_add<mint>> g(n);
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(x, y, w);
      meion [ok, val] = g.get_path(x, y);
      UL(not ok or val == w);
      g.merge(x, y, w);
    } else {
      LL(x, y);
      meion [ok, w] = g.get_path(x, y);
      UL(ok ? w.val : -1);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"