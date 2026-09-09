#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(x);
  ll s = 0, c = 1;
  for (; x; x >>= 1, c <<= 1) s += c;
  print(s);
}

int main() { Yorisou(); }