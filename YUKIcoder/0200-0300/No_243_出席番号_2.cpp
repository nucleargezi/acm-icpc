#include "YRS/all.hpp"
#include "YRS/mod/binom.hpp"

using mint = M11;
binom<mint> X;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> c(N);
  for (int x : a) if (x < N) ++c[x];
  vc<mint> dp{1};
  FOR(i, N) if (c[i]) {
    dp.ep();
    FOR_R(t, len(dp) - 1) dp[t + 1] += dp[t] * c[i];
  }
  mint s;
  FOR_R(i, len(dp)) {
    if (i & 1) s -= dp[i] * X.fac(N - i);
    else s += dp[i] * X.fac(N - i);
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"