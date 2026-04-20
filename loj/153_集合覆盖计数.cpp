#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/sps/zeta.hpp"

using mint = M99;
binom<mint> X;
void Yorisou() {
  INT(n, M, K);
  int N = 1 << n;
  vc<mint> c(N);
  FOR(M) {
    INT(x);
    c[x] += 1;
  }
  subset_zeta(c);
  vc<mint> rs(M + 1);
  FOR(i, M + 1) {
    mint c = 1, s = 1;
    FOR(k, 1, min(K, i) + 1) {
      c *= i - k + 1;
      c *= X.inv(k);
      s += c;
    }
    rs[i] = s;
  }
  vc<mint> f(N);
  FOR(s, N) f[s] = rs[c[s].val()];
  subset_mobius(f);
  print(f[N - 1]);
}

int main() {
  Yorisou();
  return 0;
}