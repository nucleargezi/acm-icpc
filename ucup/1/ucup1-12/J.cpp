#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/hull.hpp"
#include "YRS/ge/basic/convex_polygon.hpp"

using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  vc<P> p(N);
  FOR(i, N) p[i] = {i, b[i]};
  p.ep(0, inf<int> / 2);
  p.ep(N - 1, inf<int> / 2);
  convex_polygon g(rearrange(p, hull(p)));
  FOR(i, N) {
    P c = {i, a[i]};
    if (g.side(c) == 1) return print("No");
  }
  print("Yes");
}

int main() {
  Yorisou();
  return 0;
}