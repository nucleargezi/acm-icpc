#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/gauss_mod23.hpp"

void Yorisou() {
  INT(N, M);
  vc<bs3> a(M, N + 1);
  FOR(i, M) FOR(k, N + 1) {
    INT(x);
    a[i].set(k, x);
  }
  print(solve_linear_mod3(N, a));
}

int main() {
  Yorisou();
  return 0;
}