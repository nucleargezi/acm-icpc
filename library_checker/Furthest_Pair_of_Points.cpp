#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/pairs/furthest_pair.hpp"

#define tests
using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  UL(furthest_pair(a));
}
#include "YRS/Z_H/main.hpp"