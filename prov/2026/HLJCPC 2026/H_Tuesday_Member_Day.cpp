#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
void Yorisou() {
  STR(s);
  int n = si(s);
  s.erase(n - 3, 1);
  i128 x = stoull(s);
  x = x * 2 - 1;
  x = x * 2 - 1;
  x -= 297;
  s.clear();
  while (x) s += char(x % 10 + '0'), x /= 10;
  reverse(s);
  s.insert(ed(s) - 2, '.');
  print(s);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}