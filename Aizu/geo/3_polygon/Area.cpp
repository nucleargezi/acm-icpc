#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  polygon seg(p);
  setp(1);
  UL(seg.area() / 2.L);
}
#include "YRS/Z_H/main.hpp"