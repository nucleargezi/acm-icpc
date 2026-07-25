#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_ops_0.hpp"

void Yorisou() {
  INT(N, M, Q);
  vc<T4<int>> a(M);
  for (Z &[op, l, r, x] : a) {
    IN(op);
    if (op == 1) IN(l, r), --l, --r;
    if (op == 2) IN(l, r, x), --l;
    if (op == 3) IN(l), --l;
  }
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  for (ll x : range_ops_0(N, a, q)) print(x);
}

int main() {
  Yorisou();
  return 0;
}