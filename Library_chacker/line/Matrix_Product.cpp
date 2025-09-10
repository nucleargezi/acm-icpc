#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/math/line/mat_op.hpp"

// #define tests
using mint = M99;
using MT = matrix_op<mint>;
void Yorisou() {
  INT(N, M, K);
  VVEC(mint, a, N, M);
  VVEC(mint, b, M, K);
  for (Z &v : MT::mul(a, b)) {
    UL(v);
  }
}
#include "YRS/Z_H/main.hpp"