#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/mat.hpp"

void Yorisou() {
  INT(N, M);
  mat<int> a(N, M), b(a);
  IN(a, b);
  print(a += b);
}

int main() {
  Yorisou();
  return 0;
}