#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(T3<ll>, e, m);
  ll ans = 0;
  for (meion &[x, y, w] : e) {
    --x, --y;
    ans += w;
    std::swap(w, x);
  }
  sort(e);
  dsu f(n);
  for (meion &[w, x, y] : e) {
    if (f.merge(x, y) or w < 0) {
      ans -= w;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"