#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int s = 0;
  for (int &x : a) s ^= (x &= 1);
  print(count(all(a), s));
}

int main() {
  Yorisou();
  return 0;
}