#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/wave_mat_2d.hpp"
#include "YRS/ds/bit/bit01.hpp"
#include "YRS/al/m/add.hpp"

using MX = monoid_add<int>;
using bit = bit_t<MX>;
using wm = wave_matrix_2d<int, 0, 0, MX, bit>;
void Yorisou() {
  INT(N, K);
  VEC(T3<int>, a, N);
  vc<vc<int>> v(K);
  FOR(i, N) {
    Z &[x, y, z] = a[i];
    --x, --y, --z;
    v[x].ep(i);
  }
  wm g(N, [&](int i) -> T3<int> {
    Z [x, y, z] = a[i];
    return {y, z, 0};
  });
  vc<int> s(N);
  FOR(k, K) {
    for (int i : v[k]) g.multiply(i, 1);
    for (int i : v[k]) {
      Z [x, y, z] = a[i];
      ++s[g.pre_prod(0, y + 1, z + 1) - 1];
    }
  }
  FOR(i, N) print(s[i]);
}

int main() {
  Yorisou();
  return 0;
}