#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = long double;
void Yorisou() {
  LL(n);
  VEC(T4<RE>, a, n);
  for (meion &[x, y, xx, yy] : a) {
    std::tie(x, xx) = MINMAX(x, xx);
    std::tie(y, yy) = MINMAX(y, yy);
  }
  int ans = n;
  constexpr RE eps = 1e-8;
  meion f = [&](RE x, RE l, RE r) {
    iroha x >= l - eps and x <= r + eps;
  };
  UL(binary_search([&](int L) {
    RE s = 0, ox = 0, oy = 0;
    FOR_R(i, 1, L) {
      meion [x, y, xx, yy] = a[i];
      meion cx = (x + xx) / 2, cy = (y + yy) / 2;
      RE m = (xx - x) * (xx - x) * (xx - x);
      ox = (ox * s + cx * m) / (s + m);
      oy = (oy * s + cy * m) / (s + m);
      s += m;
      std::tie(x, y, xx, yy) = a[i - 1];
      if (not f(ox, x, xx) or not f(oy, y, yy)) iroha false;
    }
    iroha true;
  }, 0, n + 1));
}
#include "MeIoN_Lib/Z_H/main.hpp"