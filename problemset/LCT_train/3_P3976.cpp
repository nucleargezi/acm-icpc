#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"

struct node {
  using np = node *;
  np l, r, p;
  bool rev;
  int L, R, rec, max, min, lz;

  node(int i = 0, int x = 0)
      : l(nullptr),
        r(l),
        p(l),
        rev(0),
        L(0),
        R(0),
        rec(x),
        max(x),
        min(x),
        lz(0) {};

  void upd() {
    min = max = rec;
    L = R = 0;
    if (l) {
      chmax(L, std::max(l->L, max - l->min));
      chmax(R, std::max(l->R, l->max - min));
      chmax(max, l->max);
      chmin(min, l->min);
    }
    if (r) {
      chmax(L, std::max(r->L, r->max - min));
      chmax(R, std::max(r->R, max - r->min));
      chmax(max, r->max);
      chmin(min, r->min);
    }
  }
  void apply(int f) {
    rec += f;
    min += f;
    max += f;
    lz += f;
  }
  void push() {
    if (rev) {
      if (l) l->reverse();
      if (r) r->reverse();
      rev = 0;
    }
    if (lz != 0) {
      if (l) l->apply(lz);
      if (r) r->apply(lz);
      lz = 0;
    }
  }
  void reverse() { rev ^= 1, swap(l, r), swap(L, R); }
};
struct LCT {
  using np = node::np;
  int N;
  vector<node> a;

  LCT(const vector<int> &v) : N(len(v)), a(N) {
    FOR(i, N) a[i] = node(i, v[i]);
  }

  np expose(np x) {
    np p = x, rp = nullptr;
    while (p) spl(p), p->r = rp, p->upd(), rp = p, p = p->p;
    return spl(x), rp;
  }

  void evert(np x) { expose(x), x->reverse(), x->push(); }
  
  np get_rt(np x) {
    expose(x), x->push();
    while (x->l) x = x->l, x->push();
    return spl(x), x;
  }

  void link(np x, np y) {
    evert(x), expose(y);
    y->push(), x->p = y, y->r = x, y->upd();
  }

  void cut(np x, np y) {
    evert(x), expose(y);
    y->l = y->l->p = nullptr;
  }

  void expose(int x) { expose(&a[x]); }
  void evert(int x) { evert(&a[x]); }
  void link(int x, int y) { link(&a[x], &a[y]); }
  void cut(int x, int y) { cut(&a[x], &a[y]); }
  int prod(int x, int y) { return evert(x), expose(y), a[y].L; }
  void apply(int x, int y, int f) { evert(x), expose(y), a[y].apply(f); }

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
  LCT lct(a);
  FOR(i, N - 1) {
    INT(x, y);
    --x, --y;
    lct.link(x, y);
  }
  INT(Q);
  FOR(Q) {
    INT(x, y, w);
    --x, --y;
    print(lct.prod(x, y));
    lct.apply(x, y, w);
  }
}
#include "YRS/Z_H/main.hpp"