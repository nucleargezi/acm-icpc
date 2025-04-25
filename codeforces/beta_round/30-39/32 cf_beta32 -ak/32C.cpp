#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, s);
  ll a = n % s, b = m % s;
  if (not a) a = s;
  if (not b) b = s;
  UL(a * b * ceil(n, s) * ceil(m, s));
}
#include "MeIoN_Lib/Z_H/main.hpp"