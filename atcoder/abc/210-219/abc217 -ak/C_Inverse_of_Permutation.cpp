#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  meion ans = argsort(a);
  FOR(i, n) ++ans[i];
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"