#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  vc<int> rs(Q);
  FOR(i, Q) {
    INT(x);
    if (not fd(a, x)) rs[i] = -1;
    else rs[i] = lb(a, x) + 1;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}