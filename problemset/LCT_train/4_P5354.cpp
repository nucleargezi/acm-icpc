#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
using X = struct {
  ull a, b;
};
X op(X L, X R) {
  X ret{};
  ret.a = (L.a & R.a) | (~L.a & R.b);
  ret.b = (L.b & R.a) | (~L.b & R.b);
  return ret;
}
X make(int op, ull x) {
  X r{-1ull, 0};
  if (op == 1) r.a &= x, r.b &= x;
  if (op == 2) r.a |= x, r.b |= x;
  if (op == 3) r.a ^= x, r.b ^= x;
  return r;
}
struct node {
  using np = node *;
  np l, r, p;
  int id;
  bool rev;
  X x, xx, mx;
  node(int i = 0) : l(nullptr), r(l), p(l), 
                    id(i), rev(0),
                    x({}), xx(x), mx(x) {}
  void upd() {
    x = xx = mx;
    if (l) x = op(l->x, x), xx = op(xx, l->xx);
    if (r) x = op(x, r->x), xx = op(r->xx, xx);
  }
  
  void push() {
    if (not rev) return;
    rev = 0;
    if (l) l->reverse();
    if (r) r->reverse();
  }

  void reverse() { rev ^= 1, swap(l, r), swap(x, xx); }
  void set(X x) { mx = x; }
};
struct LCT {
  using np = node::np;
  int N;
  vector<node> a;

  LCT(int N = 0) : N(N), a(N) {
    FOR(i, N) a[i] = node(i);
  }

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
  void set(np p, X x) { evert(p), p->set(x); }

  int expose(int x) {
    np t = expose(&a[x]);
    return t ? t->id : -1;
  }
  void evert(int x) { evert(&a[x]); }
  void link(int x, int y) { link(&a[x], &a[y]); }
  void cut(int x, int y) { cut(&a[x], &a[y]); } 
  void set(int p, X x) { set(&a[p], x); }
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
  INT(N, Q, K);
  LCT lct(N);
  FOR(i, N) {
    INT(op);
    ull x;
    IN(x);
    lct.a[i].mx = make(op, x);
  }
  FOR(i, N - 1) {
    INT(x, y);
    --x, --y;
    lct.link(x, y);
  }
  FOR(Q) {
    INT(op, x, y);
    ull w;
    IN(w);
    if (op == 1) {
      --x, --y;
      Z [O, E] = lct.prod(x, y);
      ull r = 0;
      FOR_R(i, 64) {
        bool x = O >> i & 1, y = E >> i & 1;
        if (y) {
          r |= 1ull << i;
        } else if (x) {
          if ((1ull << i) <= w) {
            r |= 1ull << i;
            w -= 1ull << i;
          } 
        }
      }
      print(r);
    } else {
      --x;
      lct.set(x, make(y, w));
    }
  }
}
#include "YRS/Z_H/main.hpp"