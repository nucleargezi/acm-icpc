#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  if (QMAX(a) == 1) return a[N - 1] = 2, print(a);
  sort(a);
  pop(a);
  a.insert(bg(a), 1);
  print(a);
}

int main() {
  Yorisou();
  return 0;
}