#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/minkovski_sum.hpp"
#include "YRS/ge/basic/convex_polygon.hpp"

using P = point<ll>;
void Yorisou() {
  INT(N, M, Q);
  VEC(P, a, N);
  VEC(P, b, M);
  for (Z &x : b) x = -x;
  convex_polygon g(minkovski_sum(rearrange(a, hull(a)), rearrange(b, hull(b))));
  FOR(Q) {
    LL(x, y);
    print(g.side({x, y}) == -1 ? 0 : 1);
  }
}

int main() {
  Yorisou();
  return 0;
}