#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> f = a;
  unique(f);
  for (int &x : a) x = lb(f, x) + 1;
  print(a);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}