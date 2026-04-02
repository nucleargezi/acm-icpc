#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/22-dis-point-arc.hpp"

// #define tests
using RE = long double;
using P = point<RE>;
void Yorisou() {
  P a, b, c, p;
  int t = 0;
  while (std::cin >> a >> b >> c >> p) {
    UL(std::format("Case {}: {:.3f}", ++t, dist_point_arc(a, b, c, p)));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"