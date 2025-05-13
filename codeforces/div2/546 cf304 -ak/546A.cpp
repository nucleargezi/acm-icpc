#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(k, n, w);
  UL(MAX(0ll, k * (w + 1) * w / 2 - n));
}
#include "MeIoN_Lib/Z_H/main.hpp"