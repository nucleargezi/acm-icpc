#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(x);
  print(x & 1 ? "Ehab" : "Mahmoud");
}

int main() {
  Yorisou();
  return 0;
}