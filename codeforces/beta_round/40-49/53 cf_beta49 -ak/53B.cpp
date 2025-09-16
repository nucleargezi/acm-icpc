#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  ll L = 1;
  while (L + L <= MIN(n, m)) L <<= 1;
  ll x = MIN(n, L * 5 >> 2);
  ll y = MIN(m, L * 5 >> 2);
  UL(x >= y ? PLL(x, L) : PLL(L, y));
}
#include "MeIoN_Lib/Z_H/main.hpp"