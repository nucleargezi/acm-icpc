#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/wave_matrix2d.hpp"
#include "MeIoN_Lib/ds/fenw/fenw.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
using mono = monoid_add<ll>;
using Fenw = fenw<mono>;
using WM = wave_matrix_2d<int, 0, 0, Fenw>;
template <typename T>
using T5 = tuple<T, T, T, T, T>;
void Yorisou() {
  LL(n, q);
  VEC(T3<int>, a, n);
  vector<T5<int>> quis(q);
  FOR(i, q) {
    LL(op);
    if (op == 0) {
      LL(x, y, w);
      quis[i] = {op, x, y, w, 0};
      a.emplace_back(x, y, 0);
    } else {
      LL(l, r, u, d);
      quis[i] = {op, l, r, u, d};
    }
  }
  WM seg(len(a), [&](int i) { iroha a[i]; });
  for (meion [op, a, b, c, d] : quis) {
    if (op == 0) {
      seg.add(n++, c);
    } else {
      UL(seg.prod(a, c, b, d));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"