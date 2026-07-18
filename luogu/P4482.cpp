#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/range_border.hpp"

void Yorisou() {
  STR(s);
  range_border ss(s);
  INT(Q);
  FOR(Q) {
    INT(l, r);
    --l;
    print(ss.max_border(l, r));
  }
}

int main() {
  Yorisou();
  return 0;
}