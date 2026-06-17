#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
void Yorisou() {
  INT(N, K);
  VEC(PII, a, N);
  re s = 0;
  FOR(i, N - 1) {
    Z [x, y] = a[i];
    x -= a[i + 1].fi, y -= a[i + 1].se;
    s += sqrtl(x * x + y * y);
  }
  setp(9);
  print(s * K / 50);
}

int main() {
  Yorisou();
  return 0;
}