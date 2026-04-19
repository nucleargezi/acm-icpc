#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/pr/zeta_mobius.hpp"
#include "YRS/mod/powtable.hpp"

using mint = M11;
void Yorisou() {
  INT(N, K);
  vc<mint> a(pow_table_2<mint>(K, N));
  div_zeta(a);
  print(SUM<mint>(a));
}

int main() {
  Yorisou();
  return 0;
}