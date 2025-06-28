#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/random/rng.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  if (len(a) == 1) iroha No();
  FOR(i, 1, n) {
    ll aa = a[i], bb = b[i];
    ll f = a[0] * bb - aa * b[0];
    if (f != 0) {
      Yes();
      vector<ll> ans(n, 0);
      if (f > 0) {
        ans[0] = a[i] + b[i];
        ans[i] = -(a[0] + b[0]);
      } else {
        ans[i] = a[0] + b[0];
        ans[0] = -(a[i] + b[i]);
      }
      iroha UL(ans);
    }
  }
  No();
}
#include "MeIoN_Lib/Z_H/main.hpp"