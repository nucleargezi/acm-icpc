#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/dmint_t.hpp"

using mint = dmint;
void Yorisou() {
  INT(N, M, P);
  VEC(int, a, N);
  mint::set_mod(P);
  binom<mint> C;
  int A = QMAX(a), K = min(M, A);
  retsu<mint> f(A + 1, K + 1);
  f[0][0] = 1;
  FOR(i, 1, A + 1) FOR(k, 1, min(i, K) + 1) {
    f[i][k] += f[i - 1][k - 1];
    f[i][k] += f[i - 1][k] * mint(k - 1);
  }
  vc<mint> fl(K + 1, 1);
  FOR(k, 1, K + 1) fl[k] = fl[k - 1] * mint(M - k + 1);

  mint s = 1;
  int pr = 0;
  vc<mint> dp(K + 1);
  for (int sz : a) {
    int g = min(sz, K);
    mint ns = 0;
    FOR(k, 1, g + 1) {
      mint w = f[sz][k] * (fl[k] * s - C.fac(k) * dp[k]);
      dp[k] = w, ns += w;
    }
    FOR(k, g + 1, pr + 1) dp[k] = 0;
    pr = g, s = ns;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}