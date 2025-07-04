#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/18_polygon_area.hpp"
#include "MeIoN_Lib/geo/5-hull.hpp"
#include "MeIoN_Lib/geo/24-polygon_cover.hpp"

// #define tests
using RE = long double;
using P = point<RE>;
constexpr RE eps = 1e-9L;
void Yorisou() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  while (IN(x1, y1, x2, y2, x3, y3, x4, y4)) {
    vector<P> a{{x1, y1}, {x1, y2}, {x2, y1}};
    vector<P> b{{x3, y3}, {x3, y4}, {x4, y4}, {x4, y3}};
    a = rearrange(a, convex_hull(a));
    b = rearrange(b, convex_hull(b));
    print("{:.8f}", polygon_area(polygon_cover<eps>(a, b)) / 2);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"