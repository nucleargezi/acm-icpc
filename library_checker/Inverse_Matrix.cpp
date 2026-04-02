#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/math/line/mat.hpp"

// #define tests
using mint = M99;
using MT = matrix<mint>;
void Yorisou() {
  LL(N);
  MT A(N);
  FOR(i, N) FOR(k, N) IN(A[i][k]);
  Z [ok, det, inv] = A.inv();
  if (not ok) return print(-1);
  FOR(i, N) FOR(k, N) cout << inv[i][k] << " \n"[k + 1 == N];
}
#include "YRS/Z_H/main.hpp"