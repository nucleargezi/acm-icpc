#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/hull.hpp"

using re = ld;
using P = point<re>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  a = rearrange(a, hull(a));
  re s = 0;
  FOR(i, si(a)) s += (a[i] - a[(i + 1) % si(a)]).length();
  setp(2);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}