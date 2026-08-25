#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_inv.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  Z f(a);
  unique(f);
  for (int &x : a) x = lb(f, x);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  for (ll x : range_inv{}.f(a, q)) print(x);
}

int main() {
  Yorisou();
  return 0;
}