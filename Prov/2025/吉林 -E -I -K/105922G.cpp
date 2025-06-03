#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, 3);
  VEC(ll, b, 3);
  int nx[]{1, 2, 0};
  int pr[]{2, 0, 1};
  ll ans = 0;
  meion x = a, y = b;
  FOR(i, 3) {
    ll d = MIN(x[i], y[nx[i]]);
    ans += d;
    x[i] -= d, y[nx[i]] -= d;
    d = MIN(x[i], y[i]);
    x[i] -= d, y[i] -= d;
  }
  ans -= SUM(x);
  std::cout << ans << ' ';
  ans = 0;
  x = a, y = b;
  FOR(i, 3) {
    ll d = MIN(x[i], y[pr[i]]);
    ans -= d;
    x[i] -= d, y[pr[i]] -= d;
    d = MIN(x[i], y[i]);
    x[i] -= d, y[i] -= d;
  }
  ans += SUM(x);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"