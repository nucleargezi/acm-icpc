#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, d, n - 1);
  LL(a, b);
  d = pre_sum(d);
  UL(d[--b] - d[--a]);
}
#include "MeIoN_Lib/Z_H/main.hpp"