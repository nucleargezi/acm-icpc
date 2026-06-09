#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  INT(Q);
  VEC(string, q, Q);
  STR(s);
  for (Z &s : q) for (char &c : s) c -= 'a';
  for (char &c : s) c -= 'a';

  sam g;
  g.build(s);
  int rs = 0;
  for (var s : q) rs += g.contains(s);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}