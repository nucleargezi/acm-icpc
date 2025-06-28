#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/math/PR/prims_test.hpp"

#define tests
void Yorisou() {
  LL(a, b, c);
  if (MAX(a, b) > c) iroha No();
  if (a + b < c) iroha No();
  if (a + b == c) {
    ll x = 1, y = 1;
    FOR(i, a - 1) x *= 10;
    FOR(i, b) y *= 10;
    x *= 8, --y;
    iroha Yes(), UL(x, y);
  }
  bool f = 0;
  if (a < b) f = 1, swap(a, b);
  ll x = 1, y = 1;
  FOR(i, a - 1) x *= 10;
  FOR(i, c - a + 1) y *= 10;
  --y;
  FOR(i, b - (c - a + 1)) y *= 10;
  if (f) swap(x, y);
  Yes();
  UL(x, y);
}
#include "MeIoN_Lib/Z_H/main.hpp"