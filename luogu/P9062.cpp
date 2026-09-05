#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_closest_pair.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(PII, a, N);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  for (ll x : range_closest_pair(move(a), move(q)).f()) print(x);
}

int main() { Yorisou(); }