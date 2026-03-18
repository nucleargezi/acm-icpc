#include "YRS/all.hpp"
#include "YRS/mod/binom.hpp"

using mint = M11;
binom<mint> X;
void Yorisou() {
  INT(N, M);
  if (M > N) return print(0);
  if (M == N) return print(X.fac(N - 1) * X.inv(2));
  if (M == 0) return print(1);
  int c = N - M;
  mint s = 0;
  FOR(i, 1, c + 1) s += X.C(c, i) * X.C(M + i - 1, i - 1);
  print(s * X.fac(N) * X.ifac(c) * mint(2).pow(-c));
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"