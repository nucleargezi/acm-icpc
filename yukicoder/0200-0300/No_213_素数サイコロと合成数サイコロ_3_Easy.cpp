#define YRSD
#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/poly/coef_of_rationals.hpp"

using mint = M11;
using fps = vc<mint>;
fps_t<mint> X;
int sz;
fps gen(const vc<int> &a, int c) {
  retsu<mint> dp(c + 1, sz);
  dp[0][0] = 1;
  for (int x : a) {
    FOR_R(j, c) FOR_R(k, sz) if (dp[j][k].val() != 0) {
      FOR(i, 1, c + 1) if (j + i <= c and k + i * x < sz) {
        dp[j + i][k + i * x] += dp[j][k];
      }
    }
  }
  return {dp[c], dp[c] + sz};
}
void Yorisou() {
  LL(N, P, C);
  vc<int> a{2, 3, 5, 7, 11, 13}, b{4, 6, 8, 9, 10, 12};
  sz = P * 13 + C * 12 + 1;
  fps f = X.conv(gen(a, P), gen(b, C));
  while (not f.empty() and f.back().val() == 0) pop(f);
  fps cp = f, ls(sz << 1);
  for (mint &x : f) x = -x;
  f[0] += 1;
  int d = min<ll>(N, sz);
  fps coef = X.coef_of_rationals(f, N - d, N);
  copy(all(coef), begin(ls) + sz - d);
  ls = X.conv(ls, cp);
  mint s;
  FOR(i, sz, sz << 1) s += ls[i];
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"