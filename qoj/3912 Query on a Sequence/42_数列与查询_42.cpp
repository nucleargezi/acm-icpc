#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_lis.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  for (int &x : a) --x;
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  for (int x : range_lis(a, q).f()) print(x);
}

int main() {
  Yorisou();
  return 0;
}