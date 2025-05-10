#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(a, b);
  ll ans = 0;
  while (b) {
    ans += a / b;
    std::tie(a, b) = PLL(b, a % b);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"