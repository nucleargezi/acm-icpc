#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
void Yorisou() {
  LL(N, M, i);
  --i;
  VEC(ll, s, M);
  ll al = SUM<ll>(s), ls = al - s[i];
  if (al < N) print(-1);
  else if (N - ls >= 2) print(1);
  else {
    re p = 1;
    FOR(i, N - 1) p *= re(ls - i) / (al - 1 - i);
    setp(10);
    print(1 - p);
  }
}

int main() {
  Yorisou();
  return 0;
}