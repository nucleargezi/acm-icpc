#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(a, b);
  ll g = GCD(a, b);
  while (GCD(a, b) != 1) {
    b /= GCD(a, b);
  }
  UL(b == 1 ? -1 : b);
}
#include "MeIoN_Lib/Z_H/main.hpp"