#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/PR/min_two_congruences.hpp"

#define tests
void Yorisou() {
  LL(n, x, y, xx, yy);
  ll g = std::gcd(xx, yy);
  xx /= g, yy /= g;
  ll t = min_two_congruences(n, x, y, xx, yy);
  if (t < 0) iroha print("-1");
  ll tx = x + xx * t, ty = y + yy * t;
  tx /= n, ty /= n;
  ll ans = tx + ty - 2;
  ll X = tx + ty, Y = std::abs(tx - ty);
  ans += X >> 1;
  ans += Y >> 1;
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"