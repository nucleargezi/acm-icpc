#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/bit2.hpp"
#include "YRS/al/m/add.hpp"

using DS = bit2<Add<int>, int, 0>;
void Yorisou() {
  INT(N, _);
  VEC(T3<int>, a, N);
  sort(a);
  vc<int> x(N), y(N);
  FOR(i, N) {
    var [_, l, r] = a[i];
    x[i] = l, y[i] = r;
  }
  DS bit(x, y);
  vc<int> rs(N);
  for (int l = 0, r; l < N; l = r) {
    r = l;
    while (r < N and get<0>(a[r]) == get<0>(a[l])) ++r;
    FOR(i, l, r) {
      var [_, x, y] = a[i];
      bit.multiply(x, y, 1);
    }
    FOR(i, l, r) {
      var [_, x, y] = a[i];
      ++rs[bit.prod(x + 1, y + 1) - 1];
    }
  }
  FOR(i, N) print(rs[i]);
}

int main() {
  Yorisou();
  return 0;
}