#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(hp, n);
  VEC(ll, a, n);
  Yes(SUM(a) > hp - 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"