#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/line.hpp"

using re = ld;
void Yorisou() {
  LL(x, y, xx, yy);
  xx = -xx;
  line<re> L(point<re>(x, y), point<re>(xx, yy));
  var [a, b, c] = L;
  setp(10);
  print(-c / b);
}

int main() {
  Yorisou();
  return 0;
}