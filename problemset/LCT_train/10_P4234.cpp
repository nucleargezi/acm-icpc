#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
using X = PII;
struct node {
  using np = node*;
  np l, r, p;
  int id, sz;
  bool rev;
  X x, mx;

  node(int i = 0) : l(nullptr), r(l), p(l), id(i), 
                    sz(1), rev(0), mx(inf<int>, i) {};
  void upd() {
    x = mx;
    if (l) chmin(x, l->x);
    if (r) chmin(x, r->x);
  }
  void push() {
    if (rev) {
      rev = 0;
      if (l) l->reverse();
      if (r) r->reverse();
    }
  }
  void reverse() { rev ^= 1, swap(l, r); }
};
struct LCT {
  using np = node::np;
  int N;
  vector<node> a;

  LCT(int N = 0) : N(N), a(N) { FOR(i, N) a[i] = i; };

  np expose(np x) {
    np p = x, rp = nullptr;
    while (p) spl(p), p->r = rp, p->upd(), rp = p, p = p->p;
    return spl(x), rp;
  }
  void evert(np x) { expose(x), x->reverse(), x->push(); }
  void link(np x, np y) {
    evert(x), expose(y);
    y->push(), x->p = y, y->r = x, y->upd();
  }
  void cut(np x, np y) {
    evert(x), expose(y);
    y->l = y->l->p = nullptr, y->upd();
  }

  int expose(int x) {
    np t = expose(&a[x]);
    return t ? t->id : -1;
  }
  void evert(int x) { evert(&a[x]); }
  void link(int x, int y) { link(&a[x], &a[y]); }
  void cut(int x, int y) { cut(&a[x], &a[y]); }
  X prod(int x, int y) { return evert(x), expose(y), a[y].x; }

  int st(np x) {
    if (not x->p) return 0;
    if (x->p->l == x) return 1;
    if (x->p->r == x) return -1;
    return 0;
  }
  void spl(np x) {
    x->push();
    while (st(x)) {
      np p = x->p, pp = p ? p->p : nullptr;
      if (st(p) == 0)
        p->push(), x->push(), ro(x);
      else
        pp->push(), p->push(), x->push(), 
        ro(st(x) == st(p) ? p : x), ro(x);
    }
  }
  void ro(np x) {
    np p = x->p, pp = p->p, c;
    if (p->l == x) c = x->r, x->r = p, p->l = c;
    else c = x->l, x->l = p, p->r = c;
    p->upd(), x->upd();
    if (pp) {
      if (pp->l == p) pp->l = x;
      else if (pp->r == p) pp->r = x;
    }
    x->p = pp, p->p = x;
    if (c) c->p = p;
  }
};
struct dsu {
  int c;
  vector<int> fa;
  dsu(int N) : c(N), fa(N, -1) {}
  int ff(int x) {
    while (fa[x] >= 0) {
      int p = fa[fa[x]];
      if (p < 0) return fa[x];
      x = fa[x] = p;
    }
    return x;
  }
  int operator[](int i) { return ff(i); }
  void merge(int x, int y) {
    x = ff(x), y = ff(y);
    if (x == y) return;
    --c;
    if (fa[x] > fa[y]) swap(x, y);
    fa[x] += fa[y];
    fa[y] = x;
  }
  bool check() { return c == 1; }
};
void Yorisou() {
  INT(N, M);
  VEC(T3<int>, e, M);
  for (Z &[x, y, w] : e) {
    --x, --y;
    swap(x, w);
  }
  sort(e);
  dsu g(N);
  LCT lct(N + M);
  int ans = inf<int>;
  multiset<int> se;
  FOR(i, M) {
    Z [w, x, y] = e[i];
    if (x == y) continue;
    lct.a[i + N].mx.fi = w;
    if (g[x] == g[y]) {
      Z [min, id] = lct.prod(x, y);
      Z [ww, xx, yy] = e[id - N];
      lct.cut(xx, id);
      lct.cut(yy, id);
      se.extract(ww);
    }
    g.merge(x, y);
    se.eb(w);
    lct.link(x, i + N);
    lct.link(y, i + N);
    if (g.check()) chmin(ans, w - *se.begin());
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"