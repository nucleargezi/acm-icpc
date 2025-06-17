#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, x, m, y);
  if (x > y) swap(x, y);
  ll ans = n + 1;
  FOR(i, m) {
    ll l = y - i - 1 - x, r = y + i + 1 - x;
    if (l >= n or l <= -n) {
      ans += 1;
    } else if (l >= 0 and r >= 0) {
      --r;
      chmin(r, n);
      ans += r - l << 1;
    } else {
      --r;
      chmin(r, n);
      ans += r + l << 1 | 1;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"