#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(x);
  print(x / 500 * 1000 + x % 500 / 5 * 5);
}

int main() { Yorisou(); }