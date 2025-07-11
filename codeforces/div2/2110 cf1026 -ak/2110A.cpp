#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  int ans = n - 1;
  sort(a);
  FOR(l, n) FOR(r, l + 1, n + 1) {
    if (a[l] + a[r - 1] & 1) continue;
    chmin(ans, l + n - r);
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"