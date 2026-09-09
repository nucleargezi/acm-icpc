#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b, c);
  a *= ceil(b, a);
  print(a <= c ? "OK" : "NG");
}

int main() { Yorisou(); }