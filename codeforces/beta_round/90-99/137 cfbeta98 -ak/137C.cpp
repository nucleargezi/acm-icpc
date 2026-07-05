#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(PII, a, N);
  sort(a);
  int s = 0;
  for (int ls = -inf<int>; var [l, r] : a) {
    if (r <= ls) ++s;
    else ls = r;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}