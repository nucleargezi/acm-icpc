#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  vector<T3<ll>> e(m);
  for (meion &[x, y, w] : e) {
    IN(x, y, w);
    --x, --y;
  }
  ll ans = (1 << 30) - 1;
  FOR_R(i, 30) {
    ans ^= 1 << i;
    dsu g(n);
    for (meion [x, y, w] : e) {
      if ((ans & w) == w) g.merge(x, y);
    }
    if (g[0] != g[n - 1]) ans ^= 1 << i;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"