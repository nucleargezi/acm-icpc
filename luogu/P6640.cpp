#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/range_lcs.hpp"

void Yorisou() {
  STR(s, t);
  for (char &c : s) c -= 'a';
  for (char &c : t) c -= 'a';
  range_lcs g(s, t);
  INT(Q);
  FOR(Q) {
    INT(l, r);
    --l;
    print(g.prod(l, r));
  }
}

int main() {
  Yorisou();
  return 0;
}