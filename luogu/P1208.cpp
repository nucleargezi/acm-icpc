#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  VEC(PII, a, M);
  sort(a);
  int s = 0;
  for (var [c, h] : a) {
    int d = min(N, h);
    N -= d;
    s += d * c;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}