#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, q);
  vector<int> ans(q);
  vector<int> c(n);
  FOR(i, q) {
    if (a[i] == 0) {
      ll mx = inf<ll>, p = -1;
      FOR(i, n) {
        if (chmin(mx, c[i])) p = i + 1;
      }
      ++c[p - 1];
      ans[i] = p;
    } else {
      ans[i] = a[i];
      ++c[a[i] - 1];
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"