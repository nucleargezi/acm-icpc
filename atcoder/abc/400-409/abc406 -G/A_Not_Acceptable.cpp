#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(a, b, c, d);
  Yes(a > c or (a == c and b >= d));
}
#include "MeIoN_Lib/Z_H/main.hpp"