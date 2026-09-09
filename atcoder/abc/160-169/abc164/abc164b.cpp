#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(a, b, c, d);
  for (bool f = 0; a > 0 and c > 0; f ^= 1) {
    if (f) a -= d;
    else c -= b;
  }
  Yes(a > 0);
}

int main() { Yorisou(); }