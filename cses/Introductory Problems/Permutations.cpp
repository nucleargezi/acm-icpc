#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  if (N == 1) return print(1);
  if (N < 4) return print("NO SOLUTION");
  vc<int> s;
  FOR(i, 2, N + 1, 2) s.ep(i);
  FOR(i, 1, N + 1, 2) s.ep(i);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}