#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = long double;
void Yorisou() {
  LL(n, V);
  VEC(ll, a, n);
  VEC(ll, b, n);
  RE x = binary_search_real([&](RE x) {
    FOR(i, n) if (a[i] * x > b[i]) iroha false;
    iroha true;
  }, 0, 1'0000, 200);
  RE ans = 0;
  FOR(i, n) ans += x * a[i];
  UL(MIN<RE>(ans, V));
}
#include "MeIoN_Lib/Z_H/main.hpp"