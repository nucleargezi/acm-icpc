#include "YRS/all.hpp"
#include "YRS/g/cactus_diameter.hpp"

void Yorisou() {
  INT(N, r);
  graph<int> g(N);
  FOR(r) {
    INT(sz);
    VEC(int, p, sz);
    FOR(i, sz - 1) g.add(p[i] - 1, p[i + 1] - 1);
  }
  g.build();
  print(cactus_diameter(g).ans());
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"