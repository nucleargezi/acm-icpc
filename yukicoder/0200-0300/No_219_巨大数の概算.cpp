#include "YRS/all.hpp"

using re = ld;
void Yorisou() {
  LL(a, b);
  re lga = log10(a) * b;
  ll w = ll(floor(lga + 1e-12l)) + 1;
  int num = floor(pow(10.l, lga - w + 2) + 1e-12l);
  print(num / 10, num % 10, w - 1);
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"