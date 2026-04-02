#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  dsu g(n);
  ll ans = -1;
  FOR(m) {
    LL(x, y);
    --x, --y;
    ans += not g.merge(x, y);
  }
  ans += g.get_comp();
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"