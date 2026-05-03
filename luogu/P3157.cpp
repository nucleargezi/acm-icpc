#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/bit2.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, y, N);
  vc<int> f(N), x(N), s(N, 1);
  FOR(i, N) f[--y[i]] = i;
  iota(all(x), 0);
  bit2<monoid_add<int>> bit(x, y, s);
  ll inv = 0;
  FOR(i, 1, N) inv += bit.prod(0, i, y[i], N);

  FOR(Q) {
    print(inv);
    INT(x);
    --x;
    int i = f[x];
    inv -= bit.prod(0, i, x + 1, N);
    inv -= bit.prod(i + 1, N, 0, x);
    bit.multiply(i, x, -1);
  }
}

int main() {
  Yorisou();
  return 0;
}