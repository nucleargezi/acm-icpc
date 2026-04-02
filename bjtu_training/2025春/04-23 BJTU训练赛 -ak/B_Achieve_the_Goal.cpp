#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, k, m);
  VEC(ll, a, n - 1);
  ll nd = n * m - SUM(a);
  UL(nd > k ? -1 : MAX(nd, 0ll));
}
#include "MeIoN_Lib/Z_H/main.hpp"