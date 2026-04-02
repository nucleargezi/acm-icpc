#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  p = rearrange(p, angle_sort(p));
  for (Z p : p) print(p);
}
#include "YRS/Z_H/main.hpp"