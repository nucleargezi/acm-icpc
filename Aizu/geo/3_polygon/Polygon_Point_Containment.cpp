#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  polygon seg(p);
  INT(Q);
  while (Q--) {
    P p;
    IN(p);
    UL(seg.side(p));
  }
}
#include "YRS/Z_H/main.hpp"