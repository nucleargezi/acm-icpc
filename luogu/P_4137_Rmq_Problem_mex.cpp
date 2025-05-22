#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/range_mex_query.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  range_mex_query<0, int> seg(a);
  seg.read_quis(q);
  for (int x : seg.solve()) UL(x);
}
#include "MeIoN_Lib/Z_H/main.hpp"