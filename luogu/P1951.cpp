#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/factors.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M99;
void Yorisou() {
  LL(N);
  mint rs = 1;
  for (Z [p, n] : factor(N)) {
    mint x = p;
    rs *= x.pow(3 * n - 2) * (x * x - 1);
  }
  print(rs);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}