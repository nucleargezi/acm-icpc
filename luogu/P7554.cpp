#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/dwave.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  dwave<18> g(a);
  FOR(Q) {
    INT(l, r);
    --l;
    print(g.maxr([&](int y, int c) { return y <= r - l - c; }, l, r).fi);
  }
}

int main() {
  Yorisou();
  return 0;
}