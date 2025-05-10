#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, K, p, x, y);
  VEC(ll, a, K);
  ll A = 0, B = 0;
  FOR(i, K) (a[i] >= y ? A : B) += 1;
  vector<ll> ans;
  while (A <= n / 2) ans += y, a += y, ++A;
  while (len(a) < n) ans += 1, a += 1;
  sort(a);
  if (a[n >> 1] >= y and SUM(a) <= x)
    UL(ans);
  else
    UL(-1);
}
#include "MeIoN_Lib/Z_H/main.hpp"