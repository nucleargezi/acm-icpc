#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/avl/avl_mset.hpp"

void Yorisou() {
  INT(N);
  avl_mset<int, 1> ds;
  vc<uint> t(N + 1);
  FOR(i, 1, N + 1) {
    INT(p, op, x);
    t[i] = t[p];
    if (op == 1) t[i] = ds.ins(t[i], x);
    if (op == 2) t[i] = ds.del(t[i], x);
    if (op == 3) print(ds.rank(t[i], x) + 1);
    if (op == 4) print(ds.kth(t[i], x - 1));
    if (op == 5) print(ds.prev(t[i], x, -inf<int>));
    if (op == 6) print(ds.next(t[i], x, inf<int>));
  }
}

int main() {
  Yorisou();
  return 0;
}