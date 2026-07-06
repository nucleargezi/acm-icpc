#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(x);
  if (x == 1) print("I love Heilongjiang");
  else if (x == 0) print("I love CCPC");
  else print("Error");
}

int main() {
  Yorisou();
  return 0;
}