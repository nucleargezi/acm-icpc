#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  int s = SUM<int>(a);
  s = ceil(s, M << 2);
  int c = 0;
  for (int x : a) c += x >= s;
  Yes(c >= M);
}

int main() { Yorisou(); }