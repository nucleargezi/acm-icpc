#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/mod/inv_fast.hpp"

using mint = M11;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  inv_fast<mint> inv;
  mint s = 0, c = 1;
  FOR_R(i, N) s += inv[a[i]] * c, c *= 998244353;
  print(s.val());
}

int main() {
  Yorisou();
  return 0;
}