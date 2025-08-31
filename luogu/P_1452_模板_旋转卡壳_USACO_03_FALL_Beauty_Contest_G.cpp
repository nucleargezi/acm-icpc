#include "YRS/all.hpp"
#include "YRS/geo/9-furthest_pair.hpp"

// #define tests
using P = point<ll>;
void Yorisou() {
  INT(n);
  VEC(P, a, n);
  meion [i, k] = furthest_pair(a);
  UL((a[i] - a[k]).square());
}
#include "YRS/Z_H/main.hpp"