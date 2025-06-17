#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  FOR_R(i, 1, n) a[i] -= a[i - 1];
  Yes(QMAX(a) <= m);
}
#include "MeIoN_Lib/Z_H/main.hpp"