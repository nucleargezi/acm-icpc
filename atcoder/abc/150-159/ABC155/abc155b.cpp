#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  bool f = 1;
  VEC(int, a, N);
  for (int x : a) if (not(x & 1)) f &= (x % 3 == 0 or x % 5 == 0);
  print(f ? "APPROVED" : "DENIED");
}

int main() { Yorisou(); }