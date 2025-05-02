#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(L, q);
  set<PLL> se{{0, L}};
  FOR(q) {
    LL(op, x);
    meion [l, r] = *--se.upper_bound({x, inf<ll>});
    if (op == 1) {
      se -= PLL{l, r};
      se += PLL{l, x};
      se += PLL(x, r);
    } else {
      UL(r - l);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"