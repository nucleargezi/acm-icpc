#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(s, N);
  VEC(int, a, N);
  print(max(-1, s - SUM<int>(a)));
}

int main() { Yorisou(); }