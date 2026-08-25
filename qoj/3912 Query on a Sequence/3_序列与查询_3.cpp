#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/sswave.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  Z f(a);
  unique(f);
  for (int &x : a) x = lb(f, x);
  sswave ds(a);
  
  int rs = 0;
  INT(Q);
  FOR(Q) {
    INT(l, r, x);
    l ^= rs;
    r ^= rs;
    x ^= rs;
    --l;
    x = ub(f, x);
    print(rs = r - l - ds.rank(l, r, x));
  }
}

int main() {
  Yorisou();
  return 0;
}