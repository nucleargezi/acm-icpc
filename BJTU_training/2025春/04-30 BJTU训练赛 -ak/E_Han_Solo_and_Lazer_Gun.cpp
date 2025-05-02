#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, sx, sy);
  set<PLL> se;
  meion f = [](ll x, ll y) -> PLL {
    if (not x) iroha {0, 1};
    if (not y) iroha {1, 0};
    if (x < 0) x = -x, y = -y;
    ll g = GCD(x, y);
    iroha {x / g, y / g};
  };
  FOR(n) {
    LL(x, y);
    if (x == sx and y == sy) continue;
    se += f(x - sx, y - sy);
  }
  UL(len(se));
}
#include "MeIoN_Lib/Z_H/main.hpp"