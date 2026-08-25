#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/range_pa_dsu.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M11;
void Yorisou() {
  INT(N, Q);
  vc<T3<int>> q(Q);
  FOR(i, Q) {
    INT(l1, r1, l2, r2);
    q[i] = {l1 - 1, l2 - 1, r1 - l1 + 1};
  }
  Z g = range_pa_dsu(N, q);
  print(mint(10).pow(g.c - 1) * 9);
}

int main() { Yorisou(); }