#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/random/rng.hpp"
#include "YRS/line/01/range_sp_range_xor.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  range_sp_range_xor<int, 30, 50> ds(a, Q);
  vc<int> qi;
  FOR(Q) {
    INT(op, l, r, x);
    --l;
    if (op == 1) ds.apply(l, r, x);
    else ds.prod(l, r, x), qi.ep(x);
  }
  for (int x : ds.slv()) print(x);
}

int main() {
  Yorisou();
  return 0;
}