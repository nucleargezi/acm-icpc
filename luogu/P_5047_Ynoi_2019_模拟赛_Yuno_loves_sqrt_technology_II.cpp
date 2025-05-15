#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/inverse_count.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  inverse_range_count f(a, 1);
  f.read_quis(q);
  for (ll x : f.count()) UL(x);
}
#include "MeIoN_Lib/Z_H/main.hpp"