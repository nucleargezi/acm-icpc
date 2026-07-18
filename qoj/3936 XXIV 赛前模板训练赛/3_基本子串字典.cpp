#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/range_border.hpp"

void Yorisou() {
  STR(s);
  range_border ss(s);
  INT(Q);
  FOR(Q) {
    INT(l, r);
    ++r;
    Z [a, b, c] = ss.prod(l, r);
    if (a == -1) print(-1);
    else print(a, b, c);
  }
}

int main() {
  Yorisou();
  return 0;
}