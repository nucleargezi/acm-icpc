#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"
#include "MeIoN_Lib/geo/20-circle_cur_line.hpp"

// #define tests
using RE = long double;
using P = point<ll>;
void Yorisou() {
  circle<ll> a, b;
  IN(a.O, a.r, b.O, b.r);
  UL(circle_cut_lines(a, b));
}
#include "MeIoN_Lib/Z_H/main.hpp"