#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/upd_diameter.hpp"
#include "YRS/ttr/sk/skewle.hpp"

void Yorisou() {
  INT(Q);
  int n = 4, a = 1, b = 2, d = 2;
  skewle g(4 + Q + Q);
  FOR(i, 1, 4) g.add(0, i);
  FOR(Q) {
    INT(f);
    --f;
    int x = n++, y = n++;
    g.add(f, x);
    g.add(f, y);
    upd_diameter(g, a, b, d, x);
    upd_diameter(g, a, b, d, y);
    print(d);
  }
}

int main() {
  Yorisou();
  return 0;
}