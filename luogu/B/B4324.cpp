#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/seq/list_monoid.hpp"
#include "YRS/ds/monoid/add.hpp"

// #define tests
using seq = list_monoid<monoid_add<int>, int, 1 << 19>;
void Yorisou() {
  INT(n, q);
  seq seg;
  FOR(i, n) seg.push_back(i, 0);
  FOR(q) {
    INT(op);
    if (op == 1) {
      INT(x, y);
      --x, --y;
      if (x == y) continue;
      seg.remove(x);
      seg.ins_L(y, x, 0);
    } else if (op == 2) {
      INT(x, y);
      --x, --y;
      if (x == y) continue;
      seg.remove(x);
      seg.ins_R(y, x, 0);
    } else {
      INT(x);
      --x;
      if (seg.contains(x)) {
        seg.remove(x);
      }
    }
  }

  if (seg.empty()) return UL("Empty!");
  int sz = seg.size_real();
  FOR(i, sz) {
    cout << seg.get(i)->first + 1 << " \n"[i + 1 == sz];
  }
}
#include "YRS/Z_H/main.hpp"