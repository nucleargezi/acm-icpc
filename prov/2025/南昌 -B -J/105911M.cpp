#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, k);
  UL(string(k, '1') + string(n - k, '4'));
}
#include "MeIoN_Lib/Z_H/main.hpp"