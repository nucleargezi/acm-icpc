#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n - 1);
  while (len(a)) {
    meion c = pre_sum<false>(a);
    UL(c);
    a.erase(a.begin());
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"