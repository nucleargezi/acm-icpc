#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(s, n);
  VEC(ll, a, n);
  sort(a);
  a = pre_sum<false>(a);
  UL(upper_bound(a, s));
}
#include "MeIoN_Lib/Z_H/main.hpp"