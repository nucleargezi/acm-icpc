#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, sz);
  vector<set<int>> a(n), b(m);
  FOR(sz) {
    LL(x, y);
    --x, --y;
    a[x] += y;
    b[y] += x;
  }
  LL(q);
  FOR(q) {
    LL(op, x);
    --x;
    if (op == 1) {
      UL(len(a[x]));
      for (int y : a[x]) {
        b[y] -= x;
      }
      a[x].clear();
    } else {
      UL(len(b[x]));
      for (int y : b[x]) {
        a[y] -= x;
      }
      b[x].clear();
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"