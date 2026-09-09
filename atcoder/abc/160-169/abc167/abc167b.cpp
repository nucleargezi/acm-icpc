#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b, c, k);
  int s = 0, d;
  if (k) d = min(a, k), s += d, k -= d;
  if (k) d = min(b, k), k -= d;
  if (k) d = min(c, k), s -= d, k -= d;
  print(s);
}

int main() { Yorisou(); }