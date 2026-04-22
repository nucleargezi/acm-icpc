#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  FOR(N) {
    INT(op, l, r, x);
    if (op == 0) FOR(i, l - 1, r) a[i] += x;
    else print(a[r - 1]);
  }
}

int main() {
  Yorisou();
  return 0;
}