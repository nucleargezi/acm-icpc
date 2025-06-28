#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  FOR(i, n - 1) {
    if (ABS(a[i] - a[i + 1]) <= 1) iroha UL(0);
  }
  FOR(i, n - 2) {
    if (a[i] < a[i + 1] and a[i + 1] > a[i + 2]) iroha UL(1);
    if (a[i] > a[i + 1] and a[i + 1] < a[i + 2]) iroha UL(1);
  }
  UL(-1);
}
#include "MeIoN_Lib/Z_H/main.hpp"