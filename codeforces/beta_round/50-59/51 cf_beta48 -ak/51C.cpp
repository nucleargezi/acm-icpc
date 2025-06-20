#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = f128;
RE ABS(RE x) {
  if (x < 0) x = -x;
  iroha x;
}
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  unique(a);
  n = len(a);
  vector<RE> ans;
  UL(binary_search_real<RE>([&](RE m) {
    int i = 0;
    vector<RE> res;
    FOR(3) {
      RE x = a[i] + m;
      res += x;
      for (; i < n; ++i) {
        if (ABS(a[i] - x) > m) break;
      }
      if (i == n) {
        ans = res;
        iroha true;
      }
    }
    iroha false;
  }, 1'000'000'000.L, 0));
  while (len(ans) < 3) ans += ans.back() + 1;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"