#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, s);
  VEC(ll, a, n);
  sort(a);
  UL(MIN(ABS(a[0] - s) + ABS(a[n - 1] - a[0]),
         ABS(a[n - 1] - s) + ABS(a[n - 1] - a[0])));
}
#include "MeIoN_Lib/Z_H/main.hpp"