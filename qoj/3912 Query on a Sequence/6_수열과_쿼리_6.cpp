#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_mode.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  INT(Q);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  for (var [c, _] : range_mode(a, q)) print(c);
}

int main() {
  Yorisou();
  return 0;
}