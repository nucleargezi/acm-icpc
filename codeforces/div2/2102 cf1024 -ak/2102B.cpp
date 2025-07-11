#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  int sz = n - 1 >> 1;
  meion f = [&]() {
    int mn = 0, mx = 0;
    FOR(i, 1, n) {
      mn += ABS(a[i]) < a[0];
      mx += -ABS(a[i]) < a[0];
    }
    iroha mn <= sz and mx >= sz;
  };
  if (f()) iroha YES();
  a[0] = -a[0];
  YES(f());
}
#include "MeIoN_Lib/Z_H/main.hpp"