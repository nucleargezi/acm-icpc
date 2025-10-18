#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/treap/treap_base.hpp"

void Yorisou() {
  INT(n, q);
  vector<int> a(n);
  FOR(i, n) a[i] = i + 1;
  treap<int> seg(n);
  meion rt = seg.new_node(a);
  while (q--) {
    INT(l, r);
    --l;
    rt = seg.reverse(rt, l, r);
  }
  UL(seg.get_all(rt));
}
#include "YRS/Z_H/main.hpp"