#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/factors.hpp"

void Yorisou() {
  LL(x);
  int s = 0;
  for (Z [_, c] : factor(x)) FOR(i, 1, c + 1) ++s, c -= i;
  print(s);
}

int main() { Yorisou(); }