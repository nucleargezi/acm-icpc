#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"
#include "YRS/ge/pairs/furthest_pair.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  meion [i, k] = furthest_pair(p);
  setp(6);
  UL((p[i] - p[k]).length());
}
#include "YRS/Z_H/main.hpp"