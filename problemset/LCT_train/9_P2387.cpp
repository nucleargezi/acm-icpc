#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
using X = PII;
struct node {
  using np = node *;
  np l, r, p;
  int id, sz;
  bool rev;
  X x, mx;

  node(int i = 0) : l(nullptr), r(l), p(l), id(i), sz(1), rev(0), mx(-1, i) {}

  void upd() {
    x = mx;
    if (l) chmax(x, l->x);
    if (r) chmax(x, r->x);
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
  
  LCT(int N = 0) : N(N), a(N) { FOR(i, N) a[i] = i; }
  
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
  void set(int x, X y) { evert(x), a[x].mx = y; }

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
  vector<int> fa;
  dsu(int N) : fa(N, -1) {}
  int operator[](int i) { return ff(i); }
  void merge(int x, int y) {
    x = ff(x), y = ff(y);
    if (x == y) return;
    if (fa[x] > fa[y]) swap(x, y);
    fa[x] += fa[y];
    fa[y] = x;
  }
  int ff(int x) {
    while (fa[x] >= 0) {
      int p = fa[fa[x]];
      if (p < 0) return fa[x];
      x = fa[x] = p;
    }
    return x;
  }
};
void Yorisou() {
  INT(N, M);
  vector<T4<int>> e(M);
  LCT lct(N + M);
  for (Z &[x, y, a, b] : e) {
    IN(x, y, a, b);
    --x, --y;
    swap(x, a), swap(y, b);
  }
  sort(e);
  FOR(i, M) {
    Z [a, b, x, y] = e[i];
    lct.a[i + N].mx.fi = b;
  }
  dsu g(N);
  int ans = inf<int>;
  FOR(i, M) {
    Z [a, b, x, y] = e[i];
    if (g[x] != g[y]) {
      lct.link(i + N, x);
      lct.link(i + N, y);
      g.merge(x, y);
    } else {
      Z [max, id] = lct.prod(x, y);
      if (max > b) {
        Z [_, __, xx, yy] = e[id - N];
        lct.cut(id, xx);
        lct.cut(id, yy);
        lct.link(x, i + N);
        lct.link(y, i + N);
      }
    }
    if (g[0] == g[N - 1]) chmin(ans, a + lct.prod(0, N - 1).fi);
  }
  print(ans == inf<int> ? -1 : ans);
}
#include "YRS/Z_H/main.hpp"