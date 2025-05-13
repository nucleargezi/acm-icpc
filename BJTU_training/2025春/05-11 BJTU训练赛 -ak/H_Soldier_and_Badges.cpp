#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  sort(a);
  vector<ll> c(QMAX(a) + n + 1);
  ll ans = 0;
  FOR(i, n) {
    ++c[a[i]];
  }
  FOR(i, len(c) - 1) {
    if (c[i] > 1) c[i + 1] += c[i] - 1, ans += c[i] - 1;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"