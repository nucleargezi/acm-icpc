#include "YRS/all.hpp"
#include "YRS/ge/exp/tri_area_me.hpp"

void Yorisou() {
  INT(N);
  VEC(T3<ll>, a, N);
  setp(1);
  print(tri_area_me{}.run(a) / 2.l);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"