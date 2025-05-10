#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, a, b);
  ll ans = n / (a + b) * a;
  n %= (a + b);
  ans += MIN(n, a);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"