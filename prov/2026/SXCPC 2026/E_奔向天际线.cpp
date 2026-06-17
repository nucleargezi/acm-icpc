#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/fset_del.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  fset_del se(N);
  FOR(i, N) if (a[i] == 1) se.erase(i);
  FOR(Q) {
    INT(x);
    --x;
    int s = 0;
    while (x < N) {
      int t = se.next(x);
      s += t - x;
      if (t == N) break;
      x = t;
      if (a[x] == 2) se.erase(x);
      int st = a[x];
      a[x] -= 1;
      chmax(a[x], 1);
      x += st;
      s += 1;
    }
    print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}