#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"

#define tests
void Yorisou() {
  LL(n, s);
  ll ans = 0;
  FOR(n) {
    LL(dx, dy, x, y);
    ans += not((x * dy - y * dx) % s);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"