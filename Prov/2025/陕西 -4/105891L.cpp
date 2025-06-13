#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  ll ans = 0;
  FOR(i, n) {
    ans += n * (i);
  }
  FOR(i, n) {
    ans += i + 1;
  }
  UL(ans << 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"