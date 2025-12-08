#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/wave/wave_mat_2d.hpp"
#include "YRS/ds/fenw/fenw01.hpp"

#define tests 0
#define fl 0
#define DB 10
using wave = wave_matrix_2d<int, 0, 0, fenw01>;
void Yorisou() {
  INT(N, K);
  VEC(T3<int>, a, N);
  vc<vc<int>> v(K);
  FOR(i, N) {
    Z &[x, y, z] = a[i];
    --x, --y, --z;
    v[x].ep(i);
  }
  wave g(N, [&](int i) -> T3<int> {
    Z [x, y, z] = a[i];
    return {y, z, 0};
  });
  vc<int> ans(N);
  FOR(k, K) {
    for (int i : v[k]) g.multiply(i, 1);
    for (int i : v[k]) {
      Z [x, y, z] = a[i];
      ++ans[g.pre_prod(0, y + 1, z + 1) - 1];
    }
  }
  FOR(i, N) print(ans[i]);
}
#include "YRS/Z_H/main.hpp"