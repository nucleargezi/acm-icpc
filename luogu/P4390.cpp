#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/wave/wave_mat_2d.hpp"
#include "YRS/ds/fenw/fenw.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(op, w);
  vc<T4<int>> q;
  vc<tuple<int, int, ll>> p;
  while (IN(op), op != 3) {
    if (op == 1) {
      INT(x, y, w);
      q.ep(-1, x, y, w);
      p.ep(x, y, 0);
    } else {
      INT(x, y, xx, yy);
      ++xx, ++yy;
      q.ep(x, xx, y, yy);
    }
  }
  int N = len(p);
  wave_matrix_2d<int, 0, 0, fenw<monoid_add<ll>>> wm(
      N, [&](int i) { return p[i]; });
  for (int t = 0; Z [x, xx, y, yy] : q) {
    if (x == -1) wm.multiply(t, yy), ++t;
    else print(wm.prod(x, xx, y, yy));
  }
}

#include "YRS/aa/main.hpp"