#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
struct LCT {
  struct node {
    using np = node *;
    np l, r, p;
    int id, sz;
    bool rev;

    node(int i = 0) : l(nullptr), r(l), p(l), id(i), sz(1), rev(0) {}

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
  using np = node *;
  int N;
  vector<node> a;
  LCT(int N = 0) : N(N), a(N) { FOR(i, N) a[i] = i; }

  void expose(np x) {
    np p = x, rp = nullptr;
    while (p) spl(p), p->r = rp, p->upd(), rp = p, p = p->p;
    spl(x);
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
  void expose(int x) { expose(&a[x]); }
  void evert(int x) { evert(&a[x]); }
  void link(int x, int y) { link(&a[x], &a[y]); }
  void cut(int x, int y) { cut(&a[x], &a[y]); }
  int prod(int x, int y) { return evert(x), expose(y), a[y].sz; }

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
      if (st(p) == 0) {
        p->push(), x->push(), ro(x);
      } else {
        pp->push(), p->push(), x->push();
        ro(st(x) == st(p) ? p : x), ro(x);
      }
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
  INT(N);
  VEC(int, a, N);
  LCT lct(N + 1);
  FOR(i, N) a[i] = min(i + a[i], N), lct.link(i, a[i]);
  INT(Q);
  FOR(Q) {
    INT(op, i);
    if (op == 1) {
      print(lct.prod(i, N) - 1);
    } else {
      INT(k);
      k = min(i + k, N);
      lct.cut(i, a[i]);
      lct.link(i, a[i] = k);
    }
  }
}
#include "YRS/Z_H/main.hpp"