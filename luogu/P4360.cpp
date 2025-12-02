#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
using X = struct {
  int w, d, s;
};
constexpr X op(X a, X b) {
  return {a.w + b.w, a.d + b.d, a.s + b.s + a.w * b.d};
}
void Yorisou() {
  INT(N);
  vc<X> a(N);
  FOR(i, N) IN(a[i].w, a[i].d), a[i].s = a[i].w * a[i].d;
  FOR(i, 1, N) a[i] = op(a[i - 1], a[i]);
  a.insert(a.begin(), {0, 0, 0});
  Z w = [&](int l, int r) {
    if (l >= r) return 0;
    return a[r].s - a[l].s - a[l].w * (a[r].d - a[l].d);
  };
  vc<int> pr(N), dp(N, inf<int>);
  FOR(i, N) pr[i] = w(0, i) + w(i + 1, N);
  Z f = [&](Z &f, int l, int r, int ql, int qr) -> void {
    if (l > r) return;
    int m = (l + r) >> 1, id = -1, nr = min(qr, m - 1);
    int e = inf<int>;
    FOR(k, ql, nr + 1) {
      if (chmin(e, pr[k] - w(k + 1, N) + 
                         w(k + 1, m) + w(m + 1, N))) 
        id = k;
    }
    dp[m] = e;
    if (l < m) f(f, l, m - 1, ql, id);
    if (m < r) f(f, m + 1, r, id, qr);
  };
  f(f, 1, N - 1, 0, N - 2);
  print(QMIN(dp));
}
#include "YRS/Z_H/main.hpp"