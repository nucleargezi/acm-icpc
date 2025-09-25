#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/dsu.hpp"

#define tests
void Yorisou() {
  INT(N, M);
  VEC(T3<int>, e, M);
  for (Z & [ x, y, w ] : e) {
    --x, --y;
    swap(x, w);
  }
  sort(e, greater());
  dsu g(N);
  int ans = 0;
  for (Z [w, x, y] : e) {
    if (w) g.merge(x, y);
    else ans += not g.merge(x, y);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"