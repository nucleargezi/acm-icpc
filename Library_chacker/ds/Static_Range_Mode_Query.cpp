#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/range_mode.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  VEC(PII, LR, q);
  for (meion [n, c] : range_mode(a, LR)) {
    UL(n, c);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"