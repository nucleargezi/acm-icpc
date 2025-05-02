#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(a, b, c);
  YES((a + b + c) % 3 == 0 and MAX(a, b) <= (a + b + c) / 3);
}
#include "MeIoN_Lib/Z_H/main.hpp"