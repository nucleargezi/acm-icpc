#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(x, y);
  FOR(i, x + 1, y) {
    if (GCD(x, i) == 1 and GCD(y, i) == 1) iroha UL(i);
  }
  UL(-1);
}
#include "MeIoN_Lib/Z_H/main.hpp"