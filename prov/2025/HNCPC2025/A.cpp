// #define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/mod/modint.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M99;
using T = pair<ll, mint>;
using RE = long double;
void Yorisou() {
  INT(N, M);
  VEC(T3<int>, e, M);
  for (Z &[x, y, w] : e) --x, --y;
  vector<T> dp(N, {inf<ll>, 0}), ndp(N);
  dp[0] = {0, 1};
  vector<tuple<int, ll, mint>> dat;
  FOR(i, N - 1) {
    fill(all(ndp), T{inf<ll>, 0});
    for (Z [x, y, w] : e) {
      for (int i = 2; i--; swap(x, y)) {
        if (dp[x].fi != inf<ll>) {
          if (chmin(ndp[y].fi, dp[x].fi + w)) ndp[y].se = dp[x].se;
          else if (ndp[y].fi == dp[x].fi + w) ndp[y].se += dp[x].se;
        }
      }
    }
    dp.swap(ndp);
    if (dp[N - 1].fi != inf<ll>) dat.ep(i + 1, dp[N - 1].fi, dp[N - 1].se);
  }
  mint ans = 0;
  const int sz = len(dat);
  FOR(i, sz) {
    Z [k, b, c] = dat[i];
    RE l = 0, r = 1'000'000'000ll * 5000 * 2;
    FOR(j, i) {
      Z [kk, bb, cc] = dat[j];
      chmin(r, binary_search_real<RE>([&](ll x) -> bool {
        return k * x + b <= kk * x + bb;
      }, -1, r + 1));
      if (l > r) break;
    }
    if (l > r) continue;
    FOR(j, i + 1, sz) {
      Z [kk, bb, cc] = dat[j];
      chmax(l, binary_search_real<RE>([&](ll x) -> bool {
        return k * x + b <= kk * x + bb;
      }, r + 1, l - 1));
      if (l > r) break;
    }
    if (l <= r) ans += c;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"