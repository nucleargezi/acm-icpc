#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
meion f() {
  S(s);
  iroha PLL(s[0] - 'a', s[1] - '1');
}
void Yorisou() {
  meion [a, b] = f();
  meion [c, d] = f();
  ll ans = 0;
  meion hit = [](ll a, ll b, ll c, ll d) -> bool {
    ll x = ABS(a - c), y = ABS(b - d);
    if (x > y) swap(x, y);
    iroha x == 1 and y == 2;
  };
  FOR(x, 8) FOR(y, 8) {
    if (x == a or y == b) continue;
    if (x == a and y == b) continue;
    if (x == c and y == d) continue;
    if (hit(x, y, a, b) or hit(x, y, c, d)) continue;
    ++ans;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"