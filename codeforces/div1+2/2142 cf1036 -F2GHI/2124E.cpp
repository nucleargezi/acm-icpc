#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  if (SUM(a) & 1) iroha print("-1");
  vector<vector<ll>> ans;
  meion PR = [&]() {
    print("{}", len(ans));
    for (meion &v : ans) {
      print("{}", v);
    }
  };
  while (QMAX(a) > 0) {
    if (len(ans) > 17) iroha print("-1");
    ll s = SUM(a), d = s >> 1;
    vector c = pre_sum<0>(a);
    FOR(i, n - 1) {
      if (c[i] == d) {
        ans += a;
        iroha PR();
      }
    }
    ll mx = 0, mi = -1;
    FOR(i, n - 1) if (c[i] < d + 1) {
      if (c[i] >= mx) {
        std::tie(mx, mi) = PLL(c[i], i);
      }
    }
    ll mn = s, ni = -1;
    FOR(i, n - 1) if (c[i] > d - 1) {
      if (c[i] <= mn) {
        std::tie(mn, ni) = PLL(c[i], i);
      }
    }
    if (mn - mx < d + 1) {
      int i = mi, k = ni;
      if (i > k) swap(i, k);
      ll t = ((k == -1) ? s : c[k]) - d;
      vector<ll> go(n);
      FOR(k, i + 1) {
        go[k] = MIN(a[k], t);
        t -= go[k];
      }
      t = ((k == -1) ? s : c[k]) - d;
      FOR(k, i + 1, n) {
        go[k] = MIN(a[k], t);
        t -= go[k];
      }
      ans += go;
      FOR(i, n) go[i] = a[i] - go[i];
      ans += go;
      iroha PR();
    } else {
      ll mx = 0, ii = -1;
      FOR(i, n - 1) if (MIN(c[i], s - c[i]) >= mx) {
        std::tie(mx, ii) = PLL(MIN(c[i], s - c[i]), i);
      }
      if (not mx) break;
      vector<ll> go(n);
      ll t = mx;
      FOR(i, ii + 1) {
        go[i] = MIN(a[i], t);
        t -= go[i];
      }
      t = mx;
      FOR(i, ii + 1, n) {
        go[i] = MIN(a[i], t);
        t -= go[i];
      }
      FOR(i, n) a[i] -= go[i];
      ans += go;
    }
  }
  if (QMAX(a) > 0) iroha print("-1");
  PR();
}
#include "MeIoN_Lib/Z_H/main.hpp"