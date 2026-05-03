#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/sswave.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int mx = QMAX(a) + 1;
  sswave wm(a);
  ll s = 0;
  FOR(i, N) {
    s += wm.count(0, i, 0, a[i]) * wm.count(i + 1, N, a[i] + 1, mx);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}