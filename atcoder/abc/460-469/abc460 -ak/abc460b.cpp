#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/circle.hpp"

using C = circle<ll>;
void Yorisou() {
  C a, b;
  IN(a.O, a.R, b.O, b.R);
  int cs = a.side(b);
  Yes(cs != 0 and cs != 4);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}