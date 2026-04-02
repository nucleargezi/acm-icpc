#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"
#include "YRS/debug.hpp"

#define tests
using RE = long double;
using P = point<RE>;
using C = circle<RE>;
void Yorisou() {
  INT(N);
  REAL(r2, r3);
  VEC(P, p, N);
  p = rearrange(p, hull(p));
  N = len(p);
  RE al = C::area(r2), c = 0;
  if (N == 1) {
    ;
  } else if (N == 2) {
    c = dist(p[0], p[1]) * 2;
    al += c * r2;
  } else {
    convex_polygon seg(p);
    al += seg.area() / 2;
    FOR(i, N) c += dist(p[i], p[(i + 1) % N]);
    al += c * r2;
  }
  RE ans = al * r3 * 2;
  ans += c * C::area(r3) / 2;
  ans += pi * pi * r2 * r3 * r3 + pi * 4 / 3 * r3 * r3 * r3;
  setp(15);
  print(ans);
}
#include "YRS/Z_H/main.hpp"