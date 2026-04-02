#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/factors.hpp"

// #define tests
void Yorisou() {
  LL(n);
  ll s = 0;
  for (meion [e, p] : factor(n)) {
    s ^= p;
  }
  Alice(s);
}
#include "MeIoN_Lib/Z_H/main.hpp"