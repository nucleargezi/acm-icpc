#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using mint = M11;
binom<mint> X;
void Yorisou() {
  INT(N, M, K);
  mint a = X.C(N - 1, K << 1), b = X.C(M - 1, K << 1);
  print(a * b);
}

int main() {
  Yorisou();
  return 0;
}