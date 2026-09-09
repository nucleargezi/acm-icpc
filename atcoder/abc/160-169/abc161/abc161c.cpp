#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(a, b);
  a %= b;
  print(min(a, b - a));
}

int main() { Yorisou(); }