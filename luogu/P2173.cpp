#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/LCT.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"

void before() {}

// #define tests
using LCT = Link_Cut_Tree<lct_node_commutative_monoid<monoid_max<int>, 0>>;
void Yorisou() {
  LL(n, m, c, q);
  VEC(int, a, n);
  vector seg(c, LCT(n));
  FOR(i, c) FOR(k, n) seg[i].set(k, a[k]);
  vector in(c, vector<int>(n));
  FOR(m) {
    LL(x, y, w);
    --x, --y;
    ++in[w][x], ++in[w][y];
    seg[w].link(x, y);
  } 
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(x, w);
      --x;
      FOR(i, c) seg[i].set(x, w);
    } else if (op == 1) {
      LL(x, y, w);
      --x, --y;
      int rc = -1;
      FOR(i, c) {
        if (seg[i].get_root(x) == seg[i].get_root(y)) {
          seg[i].evert(x);
          if (seg[i].get_fa(y) == x) {
            rc = i;
            break;
          }
        }
      }
      if (rc == -1) {
        UL("No such edge.");
      } else if (rc == w) {
        UL("Success.");
      } else if (MAX(in[w][x], in[w][y]) >= 2) {
        UL("Error 1.");
      } else if (seg[w].get_root(x) == seg[w].get_root(y)) {
        UL("Error 2.");
      } else {
        --in[rc][x], --in[rc][y];
        ++in[w][x], ++in[w][y];
        seg[rc].cut(x, y);
        seg[w].link(x, y);
        UL("Success.");
      }
    } else {
      LL(w, x, y);
      --x, --y;
      UL(seg[w].get_root(x) == seg[w].get_root(y) ? seg[w].prod_path(x, y) : -1);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"