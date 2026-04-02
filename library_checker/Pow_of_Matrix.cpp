#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/math/line/mat.hpp"

// #define tests
using mint = M99;
using MT = matrix<mint>;
void Yorisou() {
  LL(N, K);
  MT a(N);
  FOR(i, N) FOR(k, N) IN(a[i][k]);
  a = a.pow(K);
  FOR(i, N) FOR(k, N) cout << a[i][k] << " \n"[k + 1 == N];
}
#include "YRS/Z_H/main.hpp"