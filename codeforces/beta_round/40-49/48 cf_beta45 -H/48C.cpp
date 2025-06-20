#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = long double;
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  RE mn = -inf<RE>, mx = -mn;
  FOR(i, n) {
    chmax(mn, RE(a[i]) / (i + 1));
    chmin(mx, RE(a[i] + 1) / (i + 1));
  }
  ll l = std::floor(mn * (n + 1));
  ll r = std::floor(mx * (n + 1) - (1e-8L));
  if (l == r) {
    UL("unique");
    UL(l);
  } else {
    UL("not unique");
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"