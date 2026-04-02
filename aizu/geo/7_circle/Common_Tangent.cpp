#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  circle<RE> a, b;
  IN(a.O, a.R, b.O, b.R);
  setp(10);
  for (meion x : sorted(a.tangent_point(b))) UL(x); 
}
#include "YRS/Z_H/main.hpp"