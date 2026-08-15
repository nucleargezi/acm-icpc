#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/qbinom.hpp"
#include "YRS/mod/dmint_t.hpp"

using mint = dmint;
void Yorisou() {
  INT(Q, p, q);
  mint::set_mod(p);
  qbinom<mint> X(q, 1'000'000'0);
  FOR(Q) {
    INT(a, b);
    print(X.C(a, b));
  }
}

int main() {
  Yorisou();
  return 0;
}