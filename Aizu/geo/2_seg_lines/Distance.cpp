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
    segment S(a, b), T(c, d);
    setp(10);
    UL(dist(S, T));
  }
}
#include "YRS/Z_H/main.hpp"