#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  circle<RE> C;
  C.O = {0, 0};
  INT(N);
  IN(C.R);
  VEC(P, p, N);
  setp(12);
  UL(C.area_ins(p));
}
#include "YRS/Z_H/main.hpp"