#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/binom.hpp"

using mint = M11;
binom<mint> C;
void Yorisou() {
  INT(N, M, K);
  if (M == 1) return print(mint(K).pow(N));
  vc<mint> dp(N + 1), ndp(N + 1);
  dp[0] = 1;
  FOR(i, 1, N + 1) {
    fill(all(ndp), 0);
    FOR(k, i + 1) {
      if (k) ndp[k] += dp[k - 1];
      if (k < i) ndp[k] += dp[k] * k;
    }
    dp.swap(ndp);
  }
  FOR(i, N) dp[i + 1] *= C.fac(i + 1);
  mint s = 0;
  if (M == 2) {
    FOR(i, 1, K + 1) if (i <= N) {
      s += C(K, i) * C(K, i) * dp[i] * dp[i];
    }
  } else {
    FOR(i, 1, K + 1) if (i <= N) {
      FOR(k, 1, i + 1) {
        s += C(K, i) * C(i, k) * C(K - i, i - k) * dp[i] * dp[i] *
             mint(k).pow(N * (M - 2));
      }
    }
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}