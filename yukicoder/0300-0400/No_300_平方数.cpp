#include "YRS/all.hpp"
#include "YRS/pr/factors.hpp"

void Yorisou() {
  LL(x);
  ll s = 1;
  for (Z [e, p] : factor(x)) if (p & 1) s *= e;
  print(s);
}

int main() {
  Yorisou();
  return 0;
}