#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll ans = 1, pr = a[0];
  FOR(i, 1, n) {
    if (a[i] > pr + 1) ++ans, pr = a[i];
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"