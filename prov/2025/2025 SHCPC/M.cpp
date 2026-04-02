#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N, x, y);
  VEC(ll, a, N);
  ll ans = inf<ll>;
  FOR(c, 30) {
    ll r = 0;
    FOR(i, N) if (a[i]) {
      ll v = a[i];
      FOR(c) {
        if (v & 1) --v, r += x;
        v >>= 1;
      }
      if (v) r += v * x;
      chmin(r, inf<ll> / 16);
    }
    chmin(ans, r + c * y);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"