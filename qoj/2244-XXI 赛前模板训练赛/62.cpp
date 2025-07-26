#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/splay/splay_monoid.hpp"
#include "MeIoN_Lib/ds/splay/node_base_splay.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  vector<int> a(n);
  FOR(i, n) a[i] = i + 1;
  splay_tree<node_base_splay<int>> seg(n);
  meion rt = seg.new_root();
  rt = seg.new_node(a);
  FOR(q) {
    LL(l, r);
    --l;
    seg.reverse(rt, l, r);
  }
  print("{}", seg.get_all(rt));
}
#include "MeIoN_Lib/Z_H/main.hpp"