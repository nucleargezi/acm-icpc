#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(a, b, c);
  std::swap(a, b);
  std::swap(a, c);
  UL(a, b, c);
}
#include "MeIoN_Lib/Z_H/main.hpp"