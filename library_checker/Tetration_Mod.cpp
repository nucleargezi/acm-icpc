#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/tetration.hpp"

void Yorisou() {
  LL(a, b, p);
  print(tetration(a, b, p));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}