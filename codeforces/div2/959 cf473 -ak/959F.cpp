#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/line/01/range_sp_online.hpp"

using mint = M11;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  range_sp_online<int, 20> seg(a);
  FOR(Q) {
    INT(a, b);
    Z bs = seg.prod(0, a);
    b = bs.min(b);
    print(b ? 0 : mint(2).pow(a - si(bs)));
  }
}

int main() {
  Yorisou();
  return 0;
}