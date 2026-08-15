#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/range/range_lis.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  for (int &x : a) --x;
  range_lis g(a);
  FOR(Q) {
    INT(l, r);
    --l;
    print(g.prod(l, r));
  }
}

int main() {
  Yorisou();
  return 0;
}