#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  ll ans = 0;
  FOR(i, n) {
    LL(a, b);
    ans += a < b;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"