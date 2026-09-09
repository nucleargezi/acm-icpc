#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(a, b, n);
  ll x = min(n, b - 1);
  print(a * x / b);
}

int main() { Yorisou(); }