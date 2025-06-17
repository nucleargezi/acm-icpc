#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m, x);
  ll ans = 0;
  FOR(i, n) FOR(k, m) {
    if (i + k & 1) continue;
    ans += x - 1 == MIN(i, k, n - i - 1, m - k - 1);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"