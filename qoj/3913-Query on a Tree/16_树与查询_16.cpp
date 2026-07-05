#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/dynamic_dec.hpp"

void Yorisou() {
  INT(N, Q);
  dynamic_dec ds(N);
  int ls = 0;
  FOR(Q) {
    INT(op, a, b);
    a = (a + ls) % N;
    b = (b + ls) % N;
    if (op == 1) ds.link(a, b);
    else print(ls = ds.prod(a, b));
  }
}

int main() {
  Yorisou();
  return 0;
}