#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/dist.hpp"

using re = ld;
using P = point<re>;
void Yorisou() {
  INT(Q);
  setp(10);
  P a, b, c;
  FOR(Q) {
    IN(a, b, c);
    print(dist(segment(a, b), c));
  }
}

int main() {
  Yorisou();
  return 0;
}