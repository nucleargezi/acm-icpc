#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  a.ep(-inf<int> / 2), a.ep(inf<int> / 2);
  sort(a);
  ll s = 0;
  FOR(Q) {
    INT(x);
    int i = lb(a, x);
    s += min(a[i] - x, x - a[i - 1]);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}