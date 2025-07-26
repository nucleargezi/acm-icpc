#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(T3<int>, e, m);
  for (meion &[x, y, w] : e) {
    --x, --y;
    swap(w, x);
  }
  sort(e);
  dsu g(n);
  ll ans = 0;
  for (meion [w, x, y] : e) {
    if (g.merge(x, y)) ans += w;
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"