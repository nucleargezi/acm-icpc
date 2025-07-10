#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  ll mn = inf<ll>, mx = -mn;
  FOR(n) {
    LL(x, y);
    chmin(mn, x + y);
    chmax(mx, x + y);
  }
  print("{}", mx - mn << 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"