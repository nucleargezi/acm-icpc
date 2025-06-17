#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  ll l = n >> 1, r = n - l;
  UL(l * r);
  FOR(i, l) FOR(k, r) {
    UL(i + 1, k + l + 1);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"