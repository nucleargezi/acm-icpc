#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/math/line/mat_op.hpp"

// #define tests
using mint = M17;
using MT = matrix_op<mint>;
using X = MT::X;
constexpr mint in = mint(10000).inv();
int N, M;
void yorisou() {
  X a = MT::make(N, N), b = MT::make(N, M);
  FOR(i, N) FOR(k, N + M) {
    INT(x);
    if (k < N) a[i][k] = in * x;
    else b[i][k - N] = in * x;
  }
  FOR(i, N) FOR(k, N) {
    if (i == k) a[i][k] = mint(1) - a[i][k];
    else a[i][k] = -a[i][k];
  }
  X x = MT::mul(std::get<2>(MT::inv(a)), b);
  print(x[0]);
}
void Yorisou() {
  while (IN(N, M)) yorisou();
}
#include "YRS/Z_H/main.hpp"