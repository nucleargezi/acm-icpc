#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(x);
  x %= 10;
  if (x == 3) print("bon");
  else if (x == 0 or x == 1 or x == 6 or x == 8) print("pon");
  else print("hon");
}

int main() { Yorisou(); }