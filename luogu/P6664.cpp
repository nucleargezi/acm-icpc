// #define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"

#define tests 0
#define fl 0
#define DB 10
struct MX {
  using X = struct {
    int mn, id, s;
  };
  static constexpr X op(X a, X b) {
    if (a.mn < b.mn) return {a.mn, a.id, a.s + b.s};
    else return {b.mn, b.id, a.s + b.s};
  }
  static constexpr X unit() { return {}; }
};
struct dsu {
  vector<int> fa;
  dsu(int N = 0) : fa(N, -1) {}

  int f(int x) {
    while (fa[x] >= 0) {
      int p = fa[fa[x]];
      if (p < 0) return fa[x];
      x = fa[x] = p;
    }
    return x;
  }

  bool merge(int x, int y) {
    x = f(x), y = f(y);
    if (x == y) return 0;
    if (fa[x] > fa[y]) swap(x, y);
    fa[x] += fa[y];
    fa[y] = x;
    return 1;
  }
};
void Yorisou() {
  INT(N, Q);
  LCT_monoid_commute<MX> lct(N + Q);
  FOR(i, N) lct.a[i].mx = {inf<int>, 0, 0};
  vector<PII> e(Q);
  dsu g(N);
  FOR(Q) {
    STR(op);
    if (op[0] == 'f') {
      INT(id, x, y, w, l);
      id += N;
      lct.a[id].mx = {w, id, l};
      if (g.merge(x, y)) {
        lct.link(x, id);
        lct.link(y, id);
      } else {
        Z [mn, i, s] = lct.prod(x, y);
        if (mn < w) {
          Z [xx, yy] = e[i - N];
          lct.cut(i, xx);
          lct.cut(i, yy);
          lct.link(id, x);
          lct.link(id, y);
        }
      }
      e[id - N] = {x, y};
    } else if (op[0] == 'm') {
      INT(x, y);
      print(g.f(x) == g.f(y) ? lct.prod(x, y).s : -1);
    } else {
      INT(id, l);
      id += N;
      lct.evert(id);
      lct.a[id].mx.s = l;
    }
  }
}
#include "YRS/Z_H/main.hpp"