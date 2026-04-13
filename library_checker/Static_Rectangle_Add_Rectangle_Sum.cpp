#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/range/rec_sum_rec_add.hpp"

using mint = M99;
void Yorisou() {
  INT(N, Q);
  rec_sum_rec_add<mint, int> ds;
  FOR(N) {
    INT(a, b, c, d, e);
    ds.add(a, c, b, d, e);
  }
  FOR(Q) {
    INT(a, b, c, d);
    ds.add(a, c, b, d);
  }
  for (mint x : ds.ke()) print(x);
}

int main() {
  Yorisou();
  return 0;
}