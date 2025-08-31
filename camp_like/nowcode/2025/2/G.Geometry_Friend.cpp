#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"
#include "MeIoN_Lib/geo/3-angle_sort.hpp"
#include "MeIoN_Lib/geo/19-polygon_contain.hpp"

#define tests
using P = point<ll>;
using RE = long double;
void Yorisou() {
  LL(n, px, py);
  VEC(P, a, n);
  for (meion &p : a) {
    p -= P{px, py};
  }
  ll mx = 0;
  for (meion p : a) chmax(mx, p.square());
  meion f = [&](ll x) -> RE {
    vector<P> np;
    for (meion p : a) if (p.square() == x) np += p;
    np += np[0];
    if (len(np) == 2) iroha pi * 2;
    RE ans = 0;
    FOR(i, len(np) - 1) {
      RE d = np[i + 1].angle() - np[i].angle();
      if (d < 0) d += pi * 2;
      chmax(ans, d);
    }
    iroha ans;
  };
  FOR(i, n) if (a[i] == P{0, 0}) {
    iroha print("{:.15f}", f(mx));
  }
  FOR(i, n) {
    meion x = a[i], y = a[(i + 1) % n];
    segment s(x, y);
    if (s.contain(P{0, 0})) {
      iroha print("{:.15f}", std::max(pi, f(mx)));
    }
  }
  if (polygon_contain<P>(a, P{0, 0})) {
    iroha print("{:.15f}", f(mx));
  }
  print("{:.15f}", pi * 2);
}
#include "MeIoN_Lib/Z_H/main.hpp"