#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/det.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> a(N, vc<int>(N));
  IN(a);
  print(det(a, 998244353));
}

int main() {
  Yorisou();
  return 0;
}