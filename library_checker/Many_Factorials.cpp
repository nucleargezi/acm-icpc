#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/fac_large.hpp"

using mint = M99;
fps_t<mint> X;
void Yorisou() {
  INT(N);
  Z f = X.fac_large();
  FOR(N) {
    INT(x);
    print(f[x]);
  }
}

int main() {
  Yorisou();
  return 0;
}