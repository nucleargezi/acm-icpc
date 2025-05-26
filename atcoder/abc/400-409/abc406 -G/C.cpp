#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll ans = 0;
  vector<ll> L(n), R(n);
  FOR(i, 1, n) if (a[i] > a[i - 1]) L[i] = L[i - 1] + 1;
  FOR_R(i, n - 1) if (a[i] < a[i + 1]) R[i] = R[i + 1] + 1;
  vector<ll> lp, rp;
  FOR(i, 1, n - 1) {
    if (a[i] > a[i - 1] and a[i] > a[i + 1]) lp += i;
    if (a[i] < a[i - 1] and a[i] < a[i + 1]) rp += i;
  }
  FOR(i, len(lp)) {
    ll l = lp[i];
    meion it = upper(rp, l);
    if (it == rp.end()) break;
    if (l == lp.back() or lp[i + 1] > *it) {
      ans += L[l] * R[*it];
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"