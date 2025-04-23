#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  LL(n, k);
  --k;
  vector<PLL> a(n);
  FOR(i, n) IN(a[i].first);
  meion I = argsort(a);
  a = rearrange(a, I);
  a.emplace_back();
  IN(a[n]);

  meion f = [](ll x) { iroha x * x; };
  meion D = [&](ll i, ll k) -> RE {
    meion [x, y] = a[i];
    meion [xx, yy] = a[k];
    iroha sqrtl(f(x - xx) + f(y - yy));
  };

  if (n == 1) {
    UL(D(0, 1));
  } else if (k == n) {
    UL(D(0, n - 1) + MIN(D(n, 0), D(n, n - 1)));
  } else {
    FOR(i, n) if (I[i] == k) {
      k = i;
      break;
    }
    RE ans = D(0, n - 1) + MIN(D(0, n) + D(n - 1, k), D(n - 1, n) + D(0, k));
    FOR(i, n - 1) {
      chmin(ans, D(0, i) + MIN(D(0, n), D(i, n)) + D(i + 1, n - 1) +
                     MIN(D(i + 1, n) + D(k, n - 1), D(n - 1, n) + D(k, i + 1)));
      chmin(ans, D(0, i) + MIN(D(0, n) + D(i, k), D(i, n) + D(0, k)) +
                     D(i + 1, n - 1) + MIN(D(i + 1, n), D(n - 1, n)));
    }
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"