#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n, k);
  VEC(ll, a, n);
  ll c = 0, mn = QMIN(a);
  FOR(i, n) {
    if (a[i] - mn > k + 1) iroha UL("Jerry");
    c += a[i] - k > mn;
  }
  if (c > 1) iroha UL("Jerry");
  UL((SUM(a) & 1 ^ 1) ? "Jerry" : "Tom");
}
#include "MeIoN_Lib/Z_H/main.hpp"