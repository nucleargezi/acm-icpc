#include "YRS/all.hpp"

void Yorisou() {
  LL(n, h, m, t);
  ll x = 60 * h + m;
  x += (n - 1) * t;
  x %= 60 * 24;
  print(x / 60);
  print(x % 60);
}

int main() {
  Yorisou();
  return 0;
}