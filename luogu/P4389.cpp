#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/f/prod_of_one_minus_xn.hpp"

using mint = M99;
void Yorisou() {
  INT(N, S);
  VEC(int, a, N);
  Z f = prod_of_one_minus_xn<mint>(a, S, 1);
  FOR(i, S) print(f[i + 1]);
}

int main() { Yorisou(); }