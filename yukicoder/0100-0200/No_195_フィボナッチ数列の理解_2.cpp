#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/line/solve_line.hpp"

using mint = M99;
void Yorisou() {
  LL(a, b, c);
  constexpr int N = 50;
  vc<ll> f(N), g(N);
  f[0] = 1, g[1] = 1;
  FOR(i, 2, N) f[i] = f[i - 1] + f[i - 2];
  FOR(i, 2, N) g[i] = g[i - 1] + g[i - 2];
  PLL ans = inf<PLL>;
  FOR(i, N) FOR(k, N) FOR(j, N) {
    vc<vc<mint>> A(3);
    A[0] = {f[i], g[i]};
    A[1] = {f[k], g[k]};
    A[2] = {f[j], g[j]};
    FOR(i, 3) FOR(k, 2) A[i][k] = A[i][k].x;
    vc<mint> B{a, b, c};
    Z r = solve_line(A, B);
    if (r.empty()) continue;

    Z ck = [&](ll aa, ll bb) -> bool {
      if (min(aa, bb) == 0) return 0;
      if (aa * f[i] + bb * g[i] != a) return 0;
      if (aa * f[k] + bb * g[k] != b) return 0;
      if (aa * f[j] + bb * g[j] != c) return 0;
      return 1;
    };
    ll aa = r[0][0].val(), bb = r[0][1].val();
    if (ck(aa, bb)) chmin(ans, PLL{aa, bb});
  }
  if (a == b and a == c) {
    FOR(i, 50) if (max(f[i], g[i]) <= a) {
      ll t = a - f[i];
      if (t == 0) {
        ans = {1, 1};
      } else if (g[i] != 0 and t % g[i] == 0) {
        chmin(ans, PLL {1, t / g[i]});
      }
    }
  }
  if (ans == inf<PLL>) print(-1);
  else print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"