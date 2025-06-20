#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  FOR(i, n) a[i] = (i + 1) % n + 1;
  UL(a);
}
#include "MeIoN_Lib/Z_H/main.hpp"