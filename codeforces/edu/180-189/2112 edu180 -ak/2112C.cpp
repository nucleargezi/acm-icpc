#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll ans = 0;
  FOR(i, 2, n) {
    int l = 0, r = i - 1;
    while (l < r) {
      if (a[l] + a[r] > MAX(a[i], a[n - 1] - a[i]))
        ans += r-- - l;
      else
        ++l;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"