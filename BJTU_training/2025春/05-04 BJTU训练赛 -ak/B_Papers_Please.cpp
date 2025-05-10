#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  bool f = 1;
  FOR(i, n) if (a[i] & 1 ^ 1) {
    f &= a[i] % 3 == 0 or a[i] % 5 == 0;
  }
  UL(f ? "APPROVED" : "DENIED");
}
#include "MeIoN_Lib/Z_H/main.hpp"