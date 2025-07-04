#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  VEC(T3<int>, e, m);
  for (meion &[x, y, w] : e) {
    --x, --y;
    swap(x, w);
  }
  sort(e);
  dsu g(n);
  vector<int> v(n, inf<int>);
  int ans = inf<int>;
  for (meion &[w, x, y] : e) {
    x = g[x], y = g[y];
    chmin(v[x], w), chmin(v[y], w);
    g.merge(x, y);
    chmin(v[g[x]], MIN(v[x], v[y]));
    if (g[0] == g[n - 1]) {
      chmin(ans, v[g[0]] + w);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"