#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/cone_dist.hpp"

using re = ld;
void Yorisou() {
  INT(R, H);
  p3<re> a, b;
  IN(a, b);
  setp(9);
  print(cone_dist{}.dist(R, H, a, b));
}

int main() {
  Yorisou();
  return 0;
}