#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b);
  ll s = 0;
  while (a >= b) s += a / b * b, a = a / b + a % b;
  print(s + a);
}

int main() {
  Yorisou();
  return 0;
}