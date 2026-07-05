#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  for (int &x : a) --x;
  a = inverse(a);
  for (int &x : a) ++x;
  print(a);
}

int main() {
  Yorisou();
  return 0;
}