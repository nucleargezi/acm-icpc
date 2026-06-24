#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  bit_t<Add<ll>> bit(a);

  FOR(Q) {
    INT(op, a, b);
    if (op == 0) bit.add(a, b);
    else print(bit.prod(a, b));
  }
}

int main() {
  Yorisou();
  return 0;
}