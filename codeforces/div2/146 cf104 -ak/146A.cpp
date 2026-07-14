#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(N);
  STR(s);
  if (N & 1) return NO();
  for (char c : s) if (c != '4' and c != '7') return NO();
  YES(SUM<int>(s) == SUM<int>(bg(s), bg(s) + N / 2) * 2);
}

int main() {
  Yorisou();
  return 0;
}