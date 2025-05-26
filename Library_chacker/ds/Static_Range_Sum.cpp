#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  a = pre_sum(a);
  FOR(q) {
    LL(l, r);
    UL(a[r] - a[l]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"