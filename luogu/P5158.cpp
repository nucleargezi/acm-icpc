#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/multi_point.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  vector<mint> x(n), y(n);
  FOR(i, n) IN(x[i], y[i]);
  UL(multipoint_interpolate(x, y));
}
#include "MeIoN_Lib/Z_H/main.hpp"