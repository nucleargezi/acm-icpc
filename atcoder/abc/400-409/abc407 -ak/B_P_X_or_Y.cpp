#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(x, y);
  ll s = 36, d = 0;
  FOR(i, 1, 7) FOR(k, 1, 7) {
    d += (i + k >= x or ABS(i - k) >= y);
  }
  UL(ld(d) / s);
}
#include "MeIoN_Lib/Z_H/main.hpp"