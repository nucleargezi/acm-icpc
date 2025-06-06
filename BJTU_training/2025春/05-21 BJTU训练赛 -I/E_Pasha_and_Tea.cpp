#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  LL(n, w);
  VEC(RE, a, n + n);
  sort(a);
  RE ans = MIN<RE>(QMIN(a), a[n] / 2);
  UL(MIN<RE>(ans * 3 * n, w));
}
#include "MeIoN_Lib/Z_H/main.hpp"