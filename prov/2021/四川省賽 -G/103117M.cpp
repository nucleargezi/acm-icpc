#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, K, x, T);
  VEC(ll, s, n);
  VEC(ll, t, K);
  VEC(ll, p, K);
  FOR(i, K) chmax(T, p[i] - t[i]);
  ll ans = 0;
  FOR(i, n) ans += s[i] * T > x - 1;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"