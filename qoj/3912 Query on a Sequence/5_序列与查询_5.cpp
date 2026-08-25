#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_dist.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  INT(Q);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  for (int x : range_dist(a, q)) print(x);
}

int main() {
  Yorisou();
  return 0;
}