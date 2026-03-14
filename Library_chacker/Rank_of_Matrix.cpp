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
  UL(MT::rank(A));
}
#include "YRS/Z_H/main.hpp"