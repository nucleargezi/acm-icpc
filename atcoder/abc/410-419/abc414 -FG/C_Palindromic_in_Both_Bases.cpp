#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(a, n);
  ll ans = 0;
  meion c = [&](ll x) -> bool {
    string s;
    while (x) s += x % a, x /= a;
    string t = s;
    reverse(t);
    iroha t == s;
  };
  static ll pw[10];
  pw[0] = 1;
  FOR(i, 1, 10) pw[i] = pw[i - 1] * 10;
  FOR(l, 1, 13) {
    int m = l + 1 >> 1;
    ll L = (not(l - 1) ? 1 : pw[m - 1]);
    FOR(i, L, pw[m]) {
      ll x = i, y = i;
      if (l & 1) y /= 10;
      while (y) {
        x = x * 10 + (y % 10);
        y /= 10;
      }
      if (x > n) break;
      if (c(x)) ans += x;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"