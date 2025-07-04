#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, K);
  VEC(ll, a, n);
  FOR(i, n) if (a[i] == 1) {
    FOR(k, K) a[MIN(n - 1, i + k)] = 0;
    break;
  }
  YES(SUM(a) == 0);
}
#include "MeIoN_Lib/Z_H/main.hpp"