#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, c, n);
  vector<ll> a(n);
  Seg<monoid_max<ll>> seg(c);
  vector<int> nx(n);
  dsu fa(n);
  FOR(i, n) {
    nx[i] = seg.max_right([&](ll x) -> bool {
      iroha x <= c[i];
    }, i);
  }
  meion f = [&](meion &f, int x, int w, int up) -> void {
    a[x] += w;
    if (a[x] > c[x]) {
      w = a[x] - c[x];
      a[x] = c[x];
      if (nx[fa[x]] == n) iroha;
      f(f, fa[nx[x]], w, x);
    }
    if (a[x] == c[x] and up != -1) {
      int to = nx[fa[x]];
      fa.merge(x, up);
      nx[fa[x]] = to;
    }
  };
  FOR(q) {
    CH(op);
    if (op == '+') {
      LL(x, w);
      f(f, --x, w, -1);
    } else {
      LL(x);
      UL(a[--x]);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"