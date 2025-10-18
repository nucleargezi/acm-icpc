#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using P = point<ll>;
void Yorisou() {
  INT(N, M, Q);
  VEC(P, A, N);
  VEC(P, B, M);
  for (Z &x : B) x = -x;
  A = rearrange(A, hull(A));
  B = rearrange(B, hull(B));
  convex_polygon seg(minkovski_sum(A, B));
  while (Q--) {
    P p;
    IN(p);
    UL(seg.side(p) == -1 ? 0 : 1);
  }
}
#include "YRS/Z_H/main.hpp"