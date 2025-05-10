#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(x, y);
  Yes((y == 1 and x >= 1600 and x < 3000) or (y == 2 and x >= 1200 and x < 2400));
}
#include "MeIoN_Lib/Z_H/main.hpp"