#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(n, R, r);
  int s;
  if (R < r) s = 0;
  else if (R < r + r) s = 1;
  else s = floor(pi / asin(1.l * r / (R - r)));
  YES(s >= n);
}

int main() {
  Yorisou();
  return 0;
}