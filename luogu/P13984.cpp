#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_mode.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> f(a);
  unique(f);
  int sz = si(f);
  for (int &x : a) x = sz - lb(f, x) - 1;
  
  VEC(PII, q, N);
  for (Z &[l, r] : q) --l;
  for (Z [c, x] : range_mode(a, q)) print(f[sz - x - 1]);
}

int main() {
  Yorisou();
  return 0;
}