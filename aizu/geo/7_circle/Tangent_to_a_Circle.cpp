#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  P p;
  circle<RE> c;
  IN(p, c.O, c.R);
  meion [ok, x, y] = c.tangent_point(p);
  if (x > y) swap(x, y);
  setp(10);
  UL(x);
  UL(y);
}
#include "YRS/Z_H/main.hpp"