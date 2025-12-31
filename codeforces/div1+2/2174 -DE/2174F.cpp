#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/mod/modint.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M17;
void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  FOR(i, N) --a[i];
  VEC(int, msk, M);
  vc<int> c(M);
  for (int x : a) ++c[x];
  if (N == 1) {
    int f = 1;
    FOR(i, M) if (msk[i]) f = 0;
    return print(f);
  }
  bool f = 0;
  FOR(i, M) if (not c[i] and msk[i] == 1) f = 1;
  if (f) return print(0);
  vc<int> A, B;
  int of = 0;
  FOR(i, M) if (c[i]) {
    ++of;
    if (not((c[i] - msk[i]) & 1)) A.ep(c[i]);
    else B.ep(c[i]);
  }
  vc<mint> dp(N + 1);
  dp[0] = 1;
  for (int x : A) FOR_R(k, x, N + 1) dp[k] += dp[k - x];
  for (int x : B) FOR_R(k, x, N + 1) dp[k] -= dp[k - x];
  int L = N - 2;
  vc<mint> g(N + 1);
  FOR(i, N + 1) g[i] = mint(N - 2 * i).pow(L);
  mint s;
  FOR(i, N + 1) if (dp[i].val) s += dp[i] * g[i];
  print(s * mint(2).inv().pow(of));
}
#include "YRS/Z_H/main.hpp"