#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b);
  print(a % b == 0);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}