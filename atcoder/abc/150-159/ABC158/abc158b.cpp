#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(N, a, b);
  ll s = N / (a + b) * a;
  N %= (a + b);
  s += min(N, a);
  print(s);
}

int main() { Yorisou(); }