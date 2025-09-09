#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  LL(Q);
  P a, b, c, d;
  while (Q--) {
    IN(a, b, c, d);
    line S(a, b), T(c, d);
    setp(10);
    UL(S.cross_point(T).second);
  }
}
#include "YRS/Z_H/main.hpp"