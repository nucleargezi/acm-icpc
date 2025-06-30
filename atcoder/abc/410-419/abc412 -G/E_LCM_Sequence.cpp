#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/primtable.hpp"

// #define tests
void Yorisou() {
  LL(l, r);
  meion pr = primtable(std::sqrt(r) + 10);
  ll N = r - l + 1;
  vector<u8> v(N, 1);
  for (ll p : pr) {
    ll t = (l + p - 1) / p * p;
    if (t < p * 2) t = p * 2;
    FOR(x, t, r + 1, p) {
      v[x - l] = 0;
    }
  }
  v[0] = l != 1;
  ll c = 0;
  FOR(i, MAX(2ll, l + 1) - l, N) {
    c += v[i];
  }
  ll ans = c + 1;
  for (ll p : pr) {
    ll t = p * p;
    if (t > r) break;
    while (t <= r) {
      if (t > l) ++ans;
      if (t > r / p) break;
      t *= p;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"