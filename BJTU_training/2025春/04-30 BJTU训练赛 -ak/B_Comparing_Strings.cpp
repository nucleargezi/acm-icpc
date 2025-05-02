#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  UL(MIN(string(n, m + '0'), string(m, n + '0')));
}
#include "MeIoN_Lib/Z_H/main.hpp"