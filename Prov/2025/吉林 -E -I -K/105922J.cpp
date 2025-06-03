#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(x, y);
  if (x & 1) std::swap(x, y);
  UL(1 + (x > y));
}
#include "MeIoN_Lib/Z_H/main.hpp"