#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(n, l, r);
  int ans = 0;
  FOR(n) {
    LL(x, y);
    ans += (l >= x and r <= y);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"