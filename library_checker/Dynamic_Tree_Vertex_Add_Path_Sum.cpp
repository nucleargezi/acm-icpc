// https://icpc.bjtu.edu.cn/problem/11427
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, Q);
  lct_mono<monoid_add<ll>> ds(N);
  FOR(i, N) {
    INT(x);
    ds[i]->mx = x;
  }
  FOR(N - 1) {
    INT(x, y);
    ds.link(x, y);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(a, b, c, d);
      ds.cut(a, b);
      ds.link(c, d);
    } else if (op == 1) {
      INT(i, x);
      ds.set(i, ds[i]->mx + x);
    } else {
      INT(x, y);
      print(ds.prod(x, y));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}