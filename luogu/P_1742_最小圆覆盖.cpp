#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/geo/17-minimum_enclosing_circle.hpp"

// #define tests
using RE = long double;
using P = point<RE>;
using C = circle<RE>;
void Yorisou() {
  INT(n);
  VEC(P, a, n);
  meion [C, i, k, j] = minimum_enclosing_circle(a);
  cout << fixed << std::setprecision(10);
  UL(C.r);
  UL(C.O.x, C.O.y);
}
#include "YRS/Z_H/main.hpp"