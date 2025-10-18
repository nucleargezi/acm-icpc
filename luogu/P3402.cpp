#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dynamic_dsu.hpp"

void before() {}

// #define tests
using dsu = dynamic_dsu<1>;
void Yorisou() {
  LL(n, q);
  dsu g(n);
  vector<dsu::np> rt(q + 1);
  rt[0] = g.new_root();
  FOR(i, 1, q + 1) {
    LL(op);
    if (op == 1) {
      LL(x, y);
      rt[i] = g.merge(rt[i - 1], --x, --y).first;
    } else if (op == 2) {
      LL(k);
      rt[i] = rt[k];
    } else {
      rt[i] = rt[i - 1];
      LL(x, y);
      UL(g.same(rt[i], --x, --y));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"