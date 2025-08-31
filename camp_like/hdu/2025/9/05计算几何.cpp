#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/geo/1-base.hpp"
#include "YRS/geo/18_polygon_area.hpp"

#define tests
using P = point<ll>;
void Yorisou() {
  INT(n);
  VEC(P, a, n);
  int f = polygon_area(a) > 0 ? 1 : -1;
  vector<tuple<ll, ll, bool>> res;
  for (int i = 0; i < n; ++i) {
    int l = (i - 1 + n) % n, r = (i + 1) % n;
    int ff = ccw(a[l], a[i], a[r]);
    if (ff) {
      res.emplace_back(a[i].x, a[i].y, f == ff);
    }
  }
  sort(res);
  UL(len(res));
  for (meion [x, y, ok] : res) {
    UL(x, y, ok ? "YES" : "NO");
  }
}
#include "YRS/Z_H/main.hpp"