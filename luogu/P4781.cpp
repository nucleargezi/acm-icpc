#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/poly/lag_t.hpp"

using mint = M99;
void Yorisou() {
  INT(N, K);
  vc<mint> a(N), b(N);
  FOR(i, N) IN(a[i], b[i]);
  print(lag_dis(a, b, K));
}

int main() {
  Yorisou();
  return 0;
}