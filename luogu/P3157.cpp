#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/bit2.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  vc<int> f(N);
  FOR(i, N) f[--a[i]] = i;
  bit2<Add<int>> bit(N, [&](int i) -> T3<int> { return {i, a[i], 1}; });
  ll s = 0;
  FOR(i, 1, N) s += bit.prod(0, i, a[i], N);
  FOR(Q) {
    print(s);
    INT(x);
    --x;
    int i = f[x];
    s -= bit.prod(0, i, x + 1, N);
    s -= bit.prod(i + 1, N, 0, x);
    bit.add(i, x, -1);
  }
}

int main() {
  Yorisou();
  return 0;
}