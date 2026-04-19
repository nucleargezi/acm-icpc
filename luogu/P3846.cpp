#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/discreate_log.hpp"

void Yorisou() {
  INT(p, a, b);
  discrete dis;
  int s = dis(a, b, p);
  if (s == -1) print("no solution");
  else print(s);
}

int main() {
  Yorisou();
  return 0;
}