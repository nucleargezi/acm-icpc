#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
namespace std {
  i128 abs(i128 x) {
    if (x < 0) x = -x;
    iroha x;
  }
}
#include "MeIoN_Lib/geo/1-base.hpp"

// #define tests
using RE = long double;
using P = point<i128>;
void Yorisou() {
  circle<i128> c;
  IN(c.O, c.r);
  LL(q);
  FOR(q) {
    PO(x, y);
    vector<point<RE>> res;
    while (len(res) < 2) 
      res += cross_point<RE>(c, line(x, y));
    sort(res);
    UL(res);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"