#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/al/m/xor.hpp"
#include "YRS/ds/frac_cas/next_prod.hpp"

void Yorisou() {
  INT(N, K, Q, D);
  vc<vc<int>> a(K, vc<int>(N));
  IN(a);
  next_prod<Xor<int>> g(a);
  int ls = 0;
  FOR(i, 1, Q + 1) {
    INT(x);
    ls = g.prod(x ^ ls);
    if (i % D == 0) print(ls);
  }
}

int main() {
  Yorisou();
  return 0;
}