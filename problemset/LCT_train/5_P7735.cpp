#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
using X = struct {
  int l, r, c;
};
using A = int;
struct MX {
  static constexpr X op(X L, X R) {
    if (L.l == -1) return R;
    if (R.r == -1) return L;
    return {L.l, R.r, L.c + R.c + (L.r == R.l)};
  }
};
constexpr X make(int x) { return {x, x, 0}; }
struct MA {
  static constexpr A op(A L, A R) {
    if (R != -1) return R;
    return L;
  }
};
constexpr X act(X x, A a, int sz) {
  if (a != -1) return {a, a, sz - 1};
  return x;
}
struct node {
  using np = node*;
  np l, r, p;
  int id, sz;
  bool rev;
  X x, xx, mx;
  A lz;

  node(int i = 0) : l(nullptr), r(l), p(l), id(i), sz(1), rev(0), lz(-1) {}

  void upd() {
    sz = 1;
    x = xx = mx;
    if (l) sz += l->sz, x = MX::op(l->x, x), xx = MX::op(xx, l->xx);
    if (r) sz += r->sz, x = MX::op(x, r->x), xx = MX::op(r->xx, xx);
  }
  void apply(A f) {
    mx = act(mx, f, 1);
    x = act(x, f, sz);
    xx = act(xx, f, sz);
    lz = MA::op(lz, f);
  }
  void push() {
    if (rev) {
      rev = 0;
      if (l) l->reverse();
      if (r) r->reverse();
    }
    if (lz != -1) {
      if (l) l->apply(lz);
      if (r) r->apply(lz);
      lz = -1;
    }
  }
  void reverse() { rev ^= 1, swap(l, r), swap(x, xx); }
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
  void apply(int x, int y, A f) { evert(x), expose(y), a[y].apply(f); }
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
void Yorisou() {
  INT(N, Q);
  LCT lct(N);
  FOR(i, N) lct.a[i].mx = make(N + Q - i);
  FOR(i, N - 1) {
    INT(x, y);
    --x, --y;
    lct.link(x, y);
  }
  FOR(i, Q) {
    INT(op, x, y);
    --x, --y;
    if (op == 1) lct.apply(x, y, i);
    else print(lct.prod(x, y).c);
  }
}
#include "YRS/Z_H/main.hpp"