#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/det.hpp"

void Yorisou() {
  INT(N, P);
  vc<vc<int>> a(N, vc<int>(N));
  IN(a);
  FOR(i, N) for (int &x : a[i]) x %= P;
  print(det(a, P));
}

int main() {
  Yorisou();
  return 0;
}