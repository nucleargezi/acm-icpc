#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(a, b, x, y);
  ll tw = MIN(x + x, x + y);
  ll c = 0, ans = inf<ll>;
  if (b >= a) {
    c += (b - a) / 2 * tw;
    a += (b - a) / 2 * 2;
  }
  if (a == b) iroha print("{}", c);
  bool ok = 0;
  if (a + 1 == b) chmin(ans, c + x);
  if ((a ^ 1) == b) chmin(ans, c + y);
  if (ans != inf<ll>) iroha print("{}", ans);
  print("{}", -1);
}
#include "MeIoN_Lib/Z_H/main.hpp"