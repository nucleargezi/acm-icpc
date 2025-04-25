#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
using RE = long double;
using P = point<RE>;
void Yorisou() {
  PO(s, t, a, b, c, d);
  segment wall(a, b), mirror(c, d);
  segment path(s, t);
  if (not seg_cross(path, wall) and not seg_cross(path, mirror)) {
    iroha YES();
  }
  t = reflection<RE>(t, mirror.to_line());
  segment mwall(reflection<RE>(a, mirror.to_line()),
      reflection<RE>(b, mirror.to_line()));
  path = segment(s, t);
  YES(seg_cross(path, mirror) and not seg_cross(path, wall) and
      not seg_cross(path, mwall));
}
#include "MeIoN_Lib/Z_H/main.hpp"