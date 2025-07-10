#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, k);
  SV(s, '0');
  k = n / 2 - k;
  ll m = std::ranges::count(s, 1);
  n -= m;
  n -= k, m -= k;
  YES(MIN(n, m) > -1 and (n & 1 ^ 1) and (m & 1 ^ 1));
}
#include "MeIoN_Lib/Z_H/main.hpp"