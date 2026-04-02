#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  circle<RE> a, b;
  IN(a.O, a.R, b.O, b.R);
  UL(a.side(b));
}
#include "YRS/Z_H/main.hpp"