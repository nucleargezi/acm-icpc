#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, c, b, d, N);
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  VEC(T3<ll>, C, N);
  vc<PLL> ps;
  FOR(i, a, b + 1) ps.ep(i, c), ps.ep(i, d);
  FOR(i, c, d + 1) ps.ep(a, i), ps.ep(b, i);
  unique(ps);
  int s = 0;
  for (var [x, y] : ps) {
    for (Z [xx, yy, r] : C) {
      xx = abs(xx - x), yy = abs(yy - y);
      if (r * r >= xx * xx + yy * yy) {
        ++s;
        break;
      }
    }
  }
  print(si(ps) - s);
}

int main() {
  Yorisou();
  return 0;
}