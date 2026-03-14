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
void Yorisou() {
  LL(n, q);
  WM seg(n, [&](int i) {
    LL(x, y, w);
    iroha T3<int>{x, y, w};
  });
  FOR(q) {
    LL(l, u, r, d);
    UL(seg.prod(l, r, u, d));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"