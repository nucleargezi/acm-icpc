#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b, c);
  print(min(a - b, c + 1));
}

int main() {
  Yorisou();
  return 0;
}