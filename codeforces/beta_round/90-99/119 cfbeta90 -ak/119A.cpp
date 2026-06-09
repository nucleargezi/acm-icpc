#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b, N);
  int c = 0;
  for (; N; c ^= 1) {
    if (c & 1) N -= gcd(N, b);
    else N -= gcd(N, a);
  }
  print(not c);
}

int main() {
  Yorisou();
  return 0;
}