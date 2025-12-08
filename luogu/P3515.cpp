#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
using RE = double;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<RE> dp(N), s(N);
  FOR(i, 1, N) s[i] = sqrtl(i);
  Z f = [&](Z &f, int l, int r, int ql, int qr) -> void {
    if (l > r) return;
    int m = (l + r) >> 1, id = -1, nr = min(qr, m - 1);
    RE e = -inf<RE>;
    FOR(k, ql, nr + 1) if (chmax(e, a[k] - a[m] + s[abs(k - m)])) id = k;
    chmax(dp[m], e);
    if (l < m) f(f, l, m - 1, ql, id);
    if (m < r) f(f, m + 1, r, id, qr);
  };
  f(f, 1, N - 1, 0, N - 2);
  vc<RE> t = dp;
  reverse(a);
  fill(all(dp), 0);
  f(f, 1, N - 1, 0, N - 2);
  reverse(dp);
  FOR(i, N) print((int)std::ceil(max(dp[i], t[i])));
}
#include "YRS/Z_H/main.hpp"