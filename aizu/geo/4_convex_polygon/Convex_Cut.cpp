#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  convex_polygon seg(p);
  INT(Q);
  setp(8);
  while (Q--) {
    P s, t;
    IN(s, t);
    convex_polygon ng(seg.convex_cut(s, t));
    UL(ng.area() / 2.L);
  }
}
#include "YRS/Z_H/main.hpp"