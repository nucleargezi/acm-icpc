#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/pairs/closest_pair.hpp"

#define tests
using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, p, N);
  UL(closest_pair(p));
}
#include "YRS/Z_H/main.hpp"