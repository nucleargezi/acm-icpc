#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add.hpp"

using DS = bit_t<monoid_add<int>>;
void Yorisou() {
  INT(N, Q);
  DS a(N), b(N);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      a.multiply(r - 1, 1);
      b.multiply(l, 1);
    } else {
      print(b.prod(r) - a.prod(l));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}