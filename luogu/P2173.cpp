#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/ds/monoid/max.hpp"

// #define tests
using LCT = LCT_monoid_commute<monoid_max<int>>;
void Yorisou() {
  INT(N, M, C, Q);
  VEC(int, a, N);
  vector<LCT> lct(C, LCT(N));
  FOR(x, C) FOR(i, N) lct[x].set(i, a[i]);
  vector in(C, vector<int>(N));
  FOR(M) {
    INT(x, y, c);
    --x, --y;
    ++in[c][x], ++in[c][y];
    lct[c].link(x, y);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y);
      --x;
      FOR(i, C) lct[i].set(x, y);
    } else if (op == 1) {
      INT(x, y, w);
      --x, --y;
      int col = -1;
      FOR(i, C) if (lct[i].evert(x), lct[i].get_fa(y) == x) {
        col = i;
        break;
      }
      if (col == -1) {
        print("No such edge.");
      } else if (col == w) {
        print("Success.");
      } else if (max(in[w][x], in[w][y]) > 1) {
        print("Error 1.");
      } else if (lct[w].get_rt(x) == lct[w].get_rt(y)) {
        print("Error 2.");
      } else {
        --in[col][x], --in[col][y];
        ++in[w][x], ++in[w][y];
        lct[col].cut(x, y);
        lct[w].link(x, y);
        print("Success.");
      }
    } else {
      INT(c, x, y);
      --x, --y;
      print(lct[c].get_rt(x) == lct[c].get_rt(y) ? lct[c].prod(x, y) : -1);
    }
  }
}
#include "YRS/Z_H/main.hpp"