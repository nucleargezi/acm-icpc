#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(x, y);
  ll ans = 0;
  ll g = std::gcd(x, y);
  x /= g, y /= g;
  if (popcount(x + y) != 1) iroha UL(-1);
  while (x != y and ans < 100) {
    ++ans;
    if (x > y) swap(x, y);
    y -= x, x += x;
  }
  UL(ans == 100 ? -1 : ans + 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"