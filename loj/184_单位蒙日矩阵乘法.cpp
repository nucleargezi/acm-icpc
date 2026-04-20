#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/nt/seaweed_doubling.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  for (int &x : a) --x;
  for (int &x : b) --x;
  a = subunit_monge_dmul(a, b);
  for (int &x : a) ++x;
  print(a);
}

int main() {
  Yorisou();
  return 0;
}