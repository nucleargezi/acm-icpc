#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, c);
  VEC(int, a, N);
  sort(a);
  ll s = 0;
  for (int x : a) s += ub(a, c + x) - lb(a, c + x);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}