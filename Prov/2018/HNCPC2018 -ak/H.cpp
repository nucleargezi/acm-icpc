#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/wave_matrix2d.hpp"
#include "YRS/ds/fenw/fenw.hpp"
#include "YRS/ds/monoid/add.hpp"

// #define tests
using mono = monoid_add<int>;
using Fenw = fenw<mono>;
using WM = wave_matrix_2d<int, 0, 0, Fenw>;
void yorisou(ll n, ll q) {
  VEC(T3<int>, go, q);
  WM seg(q, [&](int i) {
    Z [op, x, y] = go[i];
    return T3<int>{x - 1, y, 0};
  });
  FOR(i, q) {
    Z [op, x, y] = go[i];
    if (op == 1) {
      seg.add(i, 1);
    } else {
      UL(seg.prod(0, x, y, n));
    }
  }
}
void Yorisou() {
  ll n, q;
  while (IN(n, q)) yorisou(n, q);
}
#include "YRS/Z_H/main.hpp"