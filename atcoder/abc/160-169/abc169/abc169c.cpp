#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;

void Yorisou() {
  LL(a);
  REAL(b);
  ll g = round(b * 100);
  print(a * g / 100);
}

int main() { Yorisou(); }