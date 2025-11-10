#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
struct LCT {
  struct node {
    using np = node *;
    np l, r, p;
    int id;
    bool rev;

    node (int i = 0) : l(nullptr), r(l), p(l), id(i), rev(0) {}

    void reverse() { rev ^= 1, swap(l, r); }

    void push() {
      if (not rev) return;
      if (l) l->reverse();
      if (r) r->reverse();
      rev = 0;
    }
  };
  using np = node::np;
  int N;
  vector<node> a;

  LCT(int N = 0) : N(N), a(N) { FOR(i, N) a[i] = node(i); }

  np expose(np x) {
    np p = x, rp = nullptr;
    while (p) spl(p), p->r = rp, rp = p, p = p->p;
    return spl(x), rp;
  }

  np get_rt(np x) {
    expose(x), x->push();
    while (x->l) x = x->l, x->push();
    return spl(x), x;
  }
  
  void evert(np x) { expose(x), x->reverse(), x->push(); }
  
  void link(np x, np y) {
    evert(x), expose(y);
    y->push(), x->p = y, y->r = x;
  }
  
  void cut(np x, np y) {
    evert(x), expose(y);
    y->l = y->l->p = nullptr;
  }
  
  int get_rt(int x) { return get_rt(&a[x])->id; }

  void link(int x, int y) { link(&a[x], &a[y]); }
  
  void cut(int x, int y) { cut(&a[x], &a[y]); }
  
  bool check(int x, int y) { return get_rt(x) == get_rt(y); }

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
  FOR(Q) {
    STR(op);
    INT(x, y);
    --x, --y;
    if (op[0] == 'Q') {
      Yes(lct.check(x, y));
    } else if (op[0] == 'C') {
      lct.link(x, y);
    } else {
      lct.cut(x, y);
    }
  }
}
#include "YRS/Z_H/main.hpp"