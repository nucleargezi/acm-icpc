#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int s = max_element(all(a)) - bg(a);
  reverse(a);
  s += min_element(all(a)) - bg(a);
  if (s >= N - 1) s -= 1;
  print(s);
}

int main() {
  Yorisou();
  return 0;
}