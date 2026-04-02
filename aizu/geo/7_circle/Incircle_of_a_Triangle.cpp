#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  P a, b, c;
  IN(a, b, c);
  triangle seg(a, b, c);
  meion C = seg.in_circle();
  setp(20);
  UL(C.O, C.R);
}
#include "YRS/Z_H/main.hpp"