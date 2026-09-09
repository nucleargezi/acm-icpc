#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int ls = N + 1, s = 0;
  for (int x : a) s += chmin(ls, x);
  print(s);
}

int main() { Yorisou(); }