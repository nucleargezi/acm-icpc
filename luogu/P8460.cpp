#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/off_line/time_line.hpp"
#include "YRS/ds/rollback/rollback_dsu.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  time_line<PII> t;
  VEC(PII, bs, M);
  unique(bs);
  for (Z [x, y] : bs) {
    --x, --y;
    t.hit({x, y}, 0);
  }

  INT(Q);
  vector<int> quis;
  FOR(i, Q) {
    INT(x, y);
    --x, --y;
    t.hit({x, y}, i);
  }

  vector go = t.keis(Q);
  vector<int> I(len(go));
  iota(all(I), 0);

  rollback_dsu g(N << 1);
  bool ok = 0;
  Z f = [&](Z &f, int l, int r, const vector<int> &I) -> void {
    if (l >= r) return;
    int t = g.time();
    bool cp = ok;
    int m = (l + r) >> 1;
    vector<int> ls, rs;
    for (int i : I) {
      Z [pl, pr, e] = go[i];
      Z [x, y] = e;
      if (pl <= l and pr >= r) {
        ok |= not g.merge(x, y + N);
      } else {
        if (pl < m) ls.ep(i);
        if (pr > m) rs.ep(i);
      }
    }
    if (l == r - 1) {
      Yes(ok);
    } else {
      f(f, l, m, ls), f(f, m, r, rs);
    }
    g.rollback(t);
    ok = cp;
  };
  f(f, 0, Q, I);
}
#include "YRS/Z_H/main.hpp"