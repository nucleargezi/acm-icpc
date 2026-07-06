#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  chmin(M, (N + 1) >> 1);
  vc<int> a(N);
  iota(all(a), 1);
  rotate(bg(a), bg(a) + M, ed(a));
  print(a);
}

int main() {
  Yorisou();
  return 0;
}