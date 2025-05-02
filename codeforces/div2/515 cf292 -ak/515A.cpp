#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(x, y, s);
  No(x + y - s & 1 or s < ABS(x) + ABS(y));
}
#include "MeIoN_Lib/Z_H/main.hpp"