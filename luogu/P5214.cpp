#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/off_line/time_line.hpp"
#include "YRS/ds/rollback/rollback_dsu.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  time_line<PII> t;
  FOR(M) {
    INT(x, y);
    --x, --y;
    if (x > y) swap(x, y);
    t.hit({x, y}, 0);
  }

  INT(Q);
  vector<int> quis;
  FOR(i, Q) {
    CH(op);
    if (op == 'D' or op == 'A') {
      INT(x, y);
      --x, --y;
      if (x > y) swap(x, y);
      quis.ep(0);
      t.hit({x, y}, i);
    } else {
      quis.ep(1);
    }
  }

  vector go = t.keis(Q);
  vector<int> I(len(go));
  iota(all(I), 0);

  vector<int> ans;
  rollback_dsu g(N);
  int s = N;
  Z f = [&](Z &f, int l, int r, const vector<int> &I) -> void {
    if (l >= r) return;
    int t = g.time();
    int cp = s;
    int m = (l + r) >> 1;
    vector<int> ls, rs;
    for (int i : I) {
      Z [pl, pr, e] = go[i];
      Z [x, y] = e;
      if (pl <= l and pr >= r) {
        s -= g.merge(x, y);
      } else {
        if (pl < m) ls.ep(i);
        if (pr > m) rs.ep(i);
      }
    }
    if (l == r - 1) {
      int op = quis[l];
      if (op == 1) ans.ep(s);
    } else {
      f(f, l, m, ls), f(f, m, r, rs);
    }
    g.rollback(t);
    s = cp;
  };
  f(f, 0, Q, I);
  for (int x : ans) print(x);
}
#include "YRS/Z_H/main.hpp"