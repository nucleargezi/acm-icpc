#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  circle<RE> a, b;
  IN(a.O, a.R, b.O, b.R);
  setp(8);
  meion [ok, x, y] = a.cross_point(b);
  if (x > y) swap(x, y);
  UL(x, y);
}
#include "YRS/Z_H/main.hpp"