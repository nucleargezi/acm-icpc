#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_rank.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  VEC(T3<int>, q, Q);
  for (Z &[l, r, d] : q) --l, ++d;
  for (int x : range_rank(a, q)) print(x);
}

int main() {
  Yorisou();
  return 0;
}