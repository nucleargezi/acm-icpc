#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  FOR(i, n - 1) if (not(a[i] + a[i + 1])) iroha YES();
  YES(SUM(a) == n);
}
#include "MeIoN_Lib/Z_H/main.hpp"