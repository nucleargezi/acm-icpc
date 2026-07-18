#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/pairs/furthest_pair.hpp"

using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  Z [i, k] = furthest_pair(a);
  print((a[i] - a[k]).length());
}

int main() {
  Yorisou();
  return 0;
}