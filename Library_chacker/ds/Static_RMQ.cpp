#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/sparse_table/st.hpp"
#include "MeIoN_Lib/ds/monoid/min.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  ST<monoid_min<int>> seg(a);
  FOR(q) {
    LL(l, r);
    UL(seg.prod(l, r));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"