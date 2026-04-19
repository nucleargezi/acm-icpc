#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/pre_sub_ils.hpp"

void Yorisou() {
  INT(Q);
  STR(s, t);
  pre_sub_lcs g(s, t);
  FOR(Q) {
    INT(n, l, r);
    print(g.lcs(n, l, r));
  }
}

int main() {
  Yorisou();
  return 0;
}