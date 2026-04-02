#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M17;
void Yorisou() {
  LL(n, K);
  VEC(ll, a, n);
  vector<ll> d;
  FOR(i, n) d += not i ? a[i] : a[i] - a[i - 1];
  vector<vector<ll>> v(K);
  FOR(i, n - K + 1) {
    v[i % K] += d[i];
  }
  mint ans = 1;
  FOR(i, K) {
    map<ll, int> m;
    for (ll x : pre_sum<false>(v[i])) {
      ++m[x];
    }
    ans *= fact<mint>(len(v[i]));
    for (meion [_, x] : m) {
      ans *= fact_inv<mint>(x);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"