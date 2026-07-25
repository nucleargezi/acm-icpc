#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_ops_1.hpp"

void Yorisou() {
  INT(N, M, Q);
  VEC(T3<int>, a, N);
  for (Z &[l, r, x] : a) --l;
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  for (ll x : range_ops_1(M, a, q)) print(x);
}

int main() {
  Yorisou();
  return 0;
}