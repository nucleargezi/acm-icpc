#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/qbinom.hpp"
#include "YRS/mod/dmint_t.hpp"

void Yorisou() {
  using mint = dmint;
  INT(T, M, Q);
  mint::set_mod(M);
  qbinom<mint> X(Q, 1'000'000'0);
  FOR(T) {
    INT(N, K);
    print(X.C(N, K));
  }
}

int main() {
  Yorisou();
  return 0;
}