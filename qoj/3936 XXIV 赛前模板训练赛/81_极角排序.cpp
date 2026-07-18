#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/angle_sort.hpp"

using P = point<i128>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  Z s(angle_sort(a));
  for (int &x : s) ++x;
  print(s);
}

int main() {
  Yorisou();
  return 0;
}