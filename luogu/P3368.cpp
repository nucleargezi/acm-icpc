#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/dual_bit.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  dual_bit<Add<int>> bit(N);
  FOR(i, N) {
    INT(x);
    bit.apply(i, i + 1, x);
  }

  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(l, r, x);
      --l;
      bit.apply(l, r, x);
    } else {
      INT(x);
      --x;
      print(bit[x]);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}