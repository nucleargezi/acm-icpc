#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  for (int pr = -inf<int>; int i : argsort(a)) {
    if (pr < a[i]) pr = a[i];
    else a[i] = pr + 1, ++pr;
  }
  print(a);
}

int main() {
  Yorisou();
  return 0;
}