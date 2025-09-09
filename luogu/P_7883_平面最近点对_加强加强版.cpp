#include "YRS/all.hpp"
#include "YRS/ge/pairs/closest_pair.hpp"

// #define tests
using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  Z [i, k] = closest_pair(p);
  UL((p[i] - p[k]).square());
}
#include "YRS/Z_H/main.hpp"