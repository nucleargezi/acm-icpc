#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

#define tests
using mint = M99;
constexpr mint inv(ll x) { iroha inv<mint>(x); }
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  vector<int> x;
  for (int i : a) if (~i) x += i;
  int N = len(x);
  sort(x);
  vector<int> p(n + 1, -1);
  FOR_R(i, N) p[x[i]] = i;
  bool f = 1;
  int sz = 0;
  vector<mint> dp(N);
  vector<int> c(n + 1);
  FOR(i, n) {
    vector<mint> ndp(N);
    if (a[i] != -1) {
      ++c[a[i]];
      ++sz;
    } else {
      mint t;
      if (f) t = 1, f = 0;
      FOR(k, N) {
        if (not k or x[k] != x[k - 1]) {
          ndp[k] += inv(sz) * c[x[k]] * t;
        }
        if (k + 1 < p[x[k]] + c[x[k]]) {
          ndp[k + 1] += inv(sz) * dp[k] * (c[x[k]] + p[x[k]] - k - 1);
        }
        t += dp[k];
      }
      --sz;
      dp.swap(ndp);
    }
  }
  UL(SUM<mint>(dp));
}
#include "MeIoN_Lib/Z_H/main.hpp"