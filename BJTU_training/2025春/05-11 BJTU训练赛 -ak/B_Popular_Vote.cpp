#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  sort(a, greater());
  Yes(a[m - 1] * 4 * m >= SUM(a));
}
#include "MeIoN_Lib/Z_H/main.hpp"