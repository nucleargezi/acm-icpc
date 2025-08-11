// #include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/IO/fast_io.hpp"
#include "MeIoN_Lib/ds/online_range_q/range_lis_query.hpp"

// #define tests
void Yorisou() {
  INT(n, q);
  VEC(int, a, n);
  FOR(i, n) --a[i];
  range_lis_quis g(a);
  while (q--) {
    INT(l, r);
    --l;
    UL(g.prod(l, r));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"