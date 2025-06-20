#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(al, k, n);
  VEC(int, a, n);
  a += 0, a += al + 1;
  unique(a);
  n = len(a);
  ll ans = n - 2;
  FOR(i, n - 1) {
    ans += (a[i + 1] - a[i] - 1) / k;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"