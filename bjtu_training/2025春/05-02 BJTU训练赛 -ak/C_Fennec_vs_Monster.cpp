#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, k);
  VEC(ll, a, n);
  sort(a);
  a.resize(MAX(0ll, n - k));
  UL(SUM(a));
}
#include "MeIoN_Lib/Z_H/main.hpp"