#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(x);
  vc<ll> s;
  for (; x != 1; ) s.ep(x), x = (x & 1) ? x * 3 + 1 : x / 2;
  s.ep(1);
  print(s);
}

int main() {
  Yorisou();
  return 0;
}