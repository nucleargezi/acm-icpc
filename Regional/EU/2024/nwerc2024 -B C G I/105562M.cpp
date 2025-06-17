#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"
#include "MeIoN_Lib/geo/6-convex_polygon.hpp"

void before() {}

// #define tests
using P = point<i128>;
using RE = long double;
i128 ABS(i128 x) {
  iroha x < 0 ? -x : x;
}
void Yorisou() {
  LL(n);
  VEC(P, a, n);
  convex_polygon g(a);
  ll s = g.area2;
  if (n == 3) iroha UL(1.L);
  if (n == 4) iroha UL(2.L);
  vector<P> c(n + 1);
  FOR(i, n) c[i + 1] = c[i] + a[i];
  i128 u = 0;
  FOR(i, 1, n - 1) {
    u += ABS((a[i] * i - c[i]).det(a[i] * (n - i - 1) - c[n] + c[i + 1]));
  }
  RE U = u, D = s;
  UL(U / D);
}
#include "MeIoN_Lib/Z_H/main.hpp"