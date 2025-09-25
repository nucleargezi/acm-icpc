#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/wave/wave_mat_2d.hpp"
#include "YRS/ds/seg/seg_base.hpp"

// #define tests
using MX = monoid_add<ll>;
using DS = Seg<MX>;
using WM = wave_matrix_2d<int, 0, 0, DS>;
using T = tuple<int, int, int, int, int>;
void Yorisou() {
  INT(N, Q);
  VEC(T3<int>, a, N);
  vector<T> quis(Q);
  FOR(i, Q) {
    INT(op);
    if (op == 0) {
      INT(x, y, w);
      quis[i] = {op, x, y, w, 0};
      a.ep(x, y, 0);
    } else {
      INT(l, r, u, d);
      quis[i] = {op, l, r, u, d};
    }
  }
  WM seg(len(a), [&](int i) { return a[i]; });
  for (int t = 0; Z [op, a, b, c, d] : quis) {
    if (op == 0) {
      seg.multiply(N + t++, c);
    } else {
      print(seg.prod(a, c, b, d));
    }
  }
}
#include "YRS/Z_H/main.hpp"