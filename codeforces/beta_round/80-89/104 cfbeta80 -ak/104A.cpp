#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  N -= 10;
  vc<int> c(12, 4);
  c[0] = 0;
  c[10] = 15;
  int s = 0;
  FOR(i, 12) if (i == N) s += c[i];
  print(s);
}

int main() {
  Yorisou();
  return 0;
}