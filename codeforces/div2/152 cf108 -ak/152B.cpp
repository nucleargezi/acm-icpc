#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M, x, y);
  --x, --y;
  ll s = 0;
  INT(Q);
  FOR(Q) {
    INT(xx, yy);
    ll d, dd;
    if (xx > 0) d = floor(N - x - 1, xx);
    else if (xx < 0) d = floor(x, -xx);
    else d = inf<int>;
    if (yy > 0) dd = floor(M - y - 1, yy);
    else if (yy < 0) dd = floor(y, -yy);
    else dd = inf<int>;
    d = min(d, dd);
    s += d;
    x += xx * d;
    y += yy * d;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}