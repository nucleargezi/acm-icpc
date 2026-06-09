#include "YRS/all.hpp"
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
int main() {
  Yorisou();
  return 0;
}