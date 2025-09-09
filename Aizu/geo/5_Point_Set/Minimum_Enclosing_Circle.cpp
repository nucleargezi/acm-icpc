#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"
#include "YRS/ge/exp/minimum_enclosing_circle.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  meion [C, i, k, j] = minimum_enclosing_circle(p);
  setp(8);
  UL(C.O, C.R);
}
#include "YRS/Z_H/main.hpp"