#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/rec_max_rec_add.hpp"

void Yorisou() {
  INT(N, M, Q);
  vc<tuple<int, int, int, int, int>> a(M);
  for (Z &[l, r, c, d, x] : a) IN(l, c, r, d, x), --l, --c;
  vc<T4<int>> q(Q);
  for (Z &[l, r, c, d] : q) IN(l, c, r, d), --l, --c;
  for (ll x : rec_max_rec_add<ll>(N, a, q)) print(x);
}

int main() {
  Yorisou();
  return 0;
}