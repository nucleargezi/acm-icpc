#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n, K);
  ll s = 0;
  FOR(i, n) s += i * (i - 1) >> 1;
  if (s + 1 < K) iroha NO();
  YES();
  ll t = 1;
  FOR_R(i, 1, n) {
    UL(t, i + 1);
    if (K - (i - 1) * i / 2 > -2) {
      K -= (i - 1) * i >> 1;
      t = i + 1;
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"