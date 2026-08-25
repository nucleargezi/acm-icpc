#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/conv_mul_trunc_ones.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  FOR_R(i, N - 1) chmin(a[i], a[i + 1]);
  for (int &x : a) ++x;
  print(SUM<mint>(conv_mul_trunc_ones<mint>(a)));
}

int main() { Yorisou(); }