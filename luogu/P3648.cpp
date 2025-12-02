#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  VEC(ll, a, N);
  vc<ll> c = pre_sum(a);
  Z w = [&](int l, int r) { return c[r] - c[l]; };
  retsu<int> fa(K, N);
  vc<ll> dp(N), ndp(N);
  int ti = 0;
  FOR(i, N - 1) dp[i] = c[i + 1] *  w(i + 1, N), fa[0][i] = i;
  Z f = [&](Z &f, int l, int r, int ql, int qr) -> void {
    if (l > r) return;
    int m = (l + r) >> 1, id = -1, nr = min(qr, m - 1);
    ll e = -1;
    FOR(k, ql, nr + 1) {
      if (chmax(e, dp[k] + w(k + 1, m + 1) * (w(m + 1, N)))) id = k;
    }
    ndp[m] = e, fa[ti + 1][m] = id;
    if (l < m) f(f, l, m - 1, ql, id);
    if (m < r) f(f, m + 1, r, id, qr);
  };
  FOR(i, 1, K) {
    f(f, i, N - 1, i - 1, N - 2);
    dp.swap(ndp);
    ++ti;
  }
  vc<int> ans;
  int x = std::max_element(all(dp)) - dp.begin();
  print(dp[x]);
  FOR_R(i, K) {
    ans.ep(x + 1);
    x = fa[i][x];
  }
  reverse(ans);
  print(ans);
}
#include "YRS/Z_H/main.hpp"