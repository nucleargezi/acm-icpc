#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/line/mat_op.hpp"

using mint = M11;
matrix_op<mint> X;
void Yorisou() {
  INT(N, M, Q);
  Z a = X.make(N, M), b = X.make(M, Q);
  IN(a, b);
  Z c = X.mul(a, b);
  for (var x : c) print(x);
}

int main() {
  Yorisou();
  return 0;
}