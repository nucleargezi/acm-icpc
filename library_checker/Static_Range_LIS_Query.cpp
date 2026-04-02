#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/online_range_q/range_lis_query.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  range_lis_quis seg(a);
  FOR(q) {
    LL(l, r);
    if (l == n)
      print("0");
    else
      print("{}", seg.prod(l, r));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"