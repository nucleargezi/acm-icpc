#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/seq/lis.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> s = lis(a);
  print(si(s));
  print(s);
}

int main() {
  Yorisou();
  return 0;
}