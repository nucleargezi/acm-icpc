#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  dsu fa(n);
  FOR(q) {
    LL(op, x, y);
    if (op == 0) {
      fa.merge(x, y);
    } else {
      UL(fa[x] == fa[y]);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"