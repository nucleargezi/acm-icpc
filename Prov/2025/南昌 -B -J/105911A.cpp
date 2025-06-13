#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(a, b, c, d);
  UL(d * (a + b + c));
}
#include "MeIoN_Lib/Z_H/main.hpp"