#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(a, b, x, y, xx, yy);
  tie(x, y) = pair{x + y, x - y};
  tie(xx, yy) = pair{xx + yy, xx - yy};
  x = floor(x, 2 * a);
  xx = floor(xx, 2 * a);
  y = floor(y, 2 * b);
  yy = floor(yy, 2 * b);
  print(max(abs(x - xx), abs(y - yy)));
}

int main() {
  Yorisou();
  return 0;
}