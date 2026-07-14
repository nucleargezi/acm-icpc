#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(K);
  VEC(int, a, 12);
  sort(a, greater());
  int s = 0;
  while (K > 0 and s < 12) K -= a[s++];
  print(K > 0 ? -1 : s);
}

int main() {
  Yorisou();
  return 0;
}