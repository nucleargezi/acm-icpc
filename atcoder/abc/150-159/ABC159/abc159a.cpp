#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b);
  print(a * (a - 1) / 2 + b * (b - 1) / 2);
}

int main() { Yorisou(); }