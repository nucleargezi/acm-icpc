#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  FOR(N) {
    INT(op, l, r, x);
    --l;
    if (op == 0) {
      FOR(i, l, r) a[i] += x;
    } else {
      int s = 0;
      x *= x;
      FOR(i, l, r) s += a[i] < x;
      print(s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}