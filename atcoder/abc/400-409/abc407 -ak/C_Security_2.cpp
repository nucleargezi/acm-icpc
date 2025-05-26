#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  SV(s, '0');
  reverse(s);
  ll ans = 0, g = 0;
  for (int x : s) {
    int d = (x - g % 10 + 10) % 10;
    ans += 1 + d;
    g += d;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"