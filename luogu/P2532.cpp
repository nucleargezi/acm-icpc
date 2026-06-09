#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/nt/bigint/big.hpp"

bigint catalan(int N) {
  using ll = bigint;
  ll s = 1, d = 1;
  FOR(i, N + 1, N + N + 1) s *= i;
  FOR(i, 1, N + 2) d *= i;
  return s / d;
}
void Yorisou() {
  INT(N);
  print(catalan(N));
}

int main() {
  Yorisou();
  return 0;
}