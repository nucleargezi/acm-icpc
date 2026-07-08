#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  sort(a);
  a = pre_sum<0>(a);
  int s = 0, c = 0;
  for (int i : a) {
    if (i - 1 < 12 * 60 - 10) ++s;
    else break;
    c += max(0, i - 350);
  }
  print(s, c);
}

int main() {
  Yorisou();
  return 0;
}