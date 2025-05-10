#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  meion [mn, mx] = MINMAX(a);
  if (mn == mx) iroha NO();
  Yes();
  FOR(i, n) a[i] = a[i] == mx ? 2 : 1;
  UL(a);
}
#include "MeIoN_Lib/Z_H/main.hpp"