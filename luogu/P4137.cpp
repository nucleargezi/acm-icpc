#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_mex.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  for (int x : range_mex(a, q)) print(x);
}

int main() {
  Yorisou();
  return 0;
}