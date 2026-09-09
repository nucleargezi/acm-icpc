#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  I128(x);
  i128 s = 100;
  int c = 0;
  while (s < x) ++c, s += s / 100;
  print(c);
}

int main() { Yorisou(); }