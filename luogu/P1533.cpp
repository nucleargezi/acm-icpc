#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/dwave.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  dwave<31> g(a);
  FOR(Q) {
    INT(l, r, k);
    --l, --k;
    print(g.kth(l, r, k));
  }
}

int main() {
  Yorisou();
  return 0;
}