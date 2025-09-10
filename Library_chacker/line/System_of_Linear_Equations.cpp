#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/math/line/mat_op.hpp"

// #define tests
using mint = M99;
using MT = matrix_op<mint>;
void Yorisou() {
  INT(N, M);
  VVEC(mint, A, N, M);
  VEC(mint, B, N);
  Z res = MT::solve_linear(A, B);
  if (res.empty()) return print(-1);
  print(len(res) - 1);
  for (Z &v : res) print(v);
}
#include "YRS/Z_H/main.hpp"