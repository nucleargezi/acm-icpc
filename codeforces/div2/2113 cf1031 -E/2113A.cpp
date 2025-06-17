#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(k, a, b, x, y);
  ll ans = 0;
  if (k >= a) {
    ll c = ceil(k - a + 1, x);
    ll t = k - c * x;
    if (t >= b) {
      c += ceil(t - b + 1, y);
    }
    chmax(ans, c);
  }
  if (k >= b) {
    ll c = ceil(k - b + 1, y);
    ll t = k - c * y;
    if (t >= a) {
      c += ceil(t - a + 1, x);
    }
    chmax(ans, c);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"