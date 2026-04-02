#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  ll ans = 0;
  FOR(i, 1, 7) FOR(k, i, 7) ans += i + k == n;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"