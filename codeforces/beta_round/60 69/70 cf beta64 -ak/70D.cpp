#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ge/ds/dynamic_hull.hpp"

// #define tests
using P = point<ll>;
void Yorisou() {
  INT(Q);
  dynamic_hull<ll> hull;
  FOR(Q) {
    INT(op, x, y);
    P p(x, y);
    if (op == 1) {
      hull.add(p);
    } else {
      YES(hull.side(p) >= 0);
    }
  }
}
#include "YRS/Z_H/main.hpp"