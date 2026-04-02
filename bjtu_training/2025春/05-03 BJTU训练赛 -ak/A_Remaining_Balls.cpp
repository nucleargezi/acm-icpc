#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s, t);
  LL(a, b);
  S(d);
  (s == d ? a : b) -= 1;
  UL(a, b);
}
#include "MeIoN_Lib/Z_H/main.hpp"