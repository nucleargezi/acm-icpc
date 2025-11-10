#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
struct node {
  using np = node *;
  np l, r, p;
  int id, sz;
  bool rev;

  node (int i = 0) : l(nullptr), r(l), p(l), id(i), sz(1), rev(0) {}

  void upd() {
    sz = 1;
    if (l) sz += l->sz;
    if (r) sz += r->sz;
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

  int dist(int x, int y) { return evert(x), expose(y), a[y].sz - 1; }

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