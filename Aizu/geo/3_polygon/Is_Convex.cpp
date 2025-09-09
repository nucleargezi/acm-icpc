#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  UL(convex_checker(p, 0));
}
#include "YRS/Z_H/main.hpp"