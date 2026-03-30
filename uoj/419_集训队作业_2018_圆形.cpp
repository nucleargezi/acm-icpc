#include "YRS/all.hpp"
#define SETP 10
#include "YRS/IO/fast_io.hpp"
#include "YRS/ge/exp/area_of_c_union.hpp"

void Yorisou() {
  INT(T, N);
  area_of_c_union<> g;
  FOR(N) {
    INT(x, y, r);
    print(g.add<ld>(x, y, r));
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"