#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/lct/lct_base.hpp"

// #define tests
using LCT = LCT_base;
void Yorisou() {
  INT(Q);
  LCT lct(Q);
  vector<T3<int>> AB(Q);
  vector<int> fa(Q);
  iota(all(fa), 0);
  FOR(i, Q) AB[i] = {i, i, 0};
  int t = 0;
  FOR(Q) {
    CH(op);
    INT(x);
    --x;
    if (op == 'B') {
      if (x != -2) {
        fa[t] = fa[x];
        Z [A, B, sz] = AB[fa[t]];
        lct.link(x, t);
        if (chmax(sz, lct.dist(t, A))) AB[fa[t]] = {t, A, sz};
        else if (chmax(sz, lct.dist(t, B))) AB[fa[t]] = {t, B, sz};
      }
      ++t;
    } else {
      Z [A, B, sz] = AB[fa[x]];
      print(max(lct.dist(A, x), lct.dist(x, B)));
    }
  }
}
#include "YRS/Z_H/main.hpp"