#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
struct LCT {
  struct node {
    using np = node *;
    np l, r, p;
    int id;
    bool rev;
    node(int i = 0) : l(nullptr), r(l), p(l), id(i), rev(0) {}
    void reverse() { rev ^= 1, swap(l, r); }
    void push() {
      if (rev) {
        rev = 0;
        if (l) l->reverse();
        if (r) r->reverse();
      }
    }
  };
  using np = node::np;
  int N;
  vector<node> a;
  LCT(int N = 0) : N(N), a(N) { FOR(i, N) a[i] = i; }
  np expose(np x) {
    np p = x, rp = nullptr;
    while (p) spl(p), p->r = rp, rp = p, p = p->p;
    return spl(x), rp;
  }
  void evert(np x) { expose(x), x->reverse(), x->push(); }
  np get(np x) {
    expose(x), x->push();
    while (x->l) x = x->l, x->push();
    return spl(x), x;
  }
  void link(np x, np y) {
    evert(x), expose(y);
    y->push(), x->p = y, y->r = x;
  } 
  void cut(np x, np y) {
    evert(x), expose(y);
    y->l = y->l->p = nullptr;
  }
  int expose(int x) {
    np t = expose(&a[x]);
    return t ? t->id : -1;
  }
  void evert(int x) { evert(&a[x]); }
  int get(int x) { return get(&a[x])->id; }
  void link(int x, int y) { link(&a[x], &a[y]); }
  void cut(int x, int y) { cut(&a[x], &a[y]); }

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
    if (pp) {
      if (pp->l == p) pp->l = x;
      else if (pp->r == p) pp->r = x;
    }
    x->p = pp, p->p = x;
    if (c) c->p = p;
  }
};
void Yorisou() {
  INT(M);
  VEC(PII, e, M);
  int N = 0;
  for (Z &[x, y] : e) {
    chmax(N, x), chmax(N, y);
    --x, --y;
  }
  LCT lct(N);
  int l = 0;
  vector<ll> a(M + 1), b(M + 1);
  Z add = [&](int l, int r) -> void {
    a[l] += M - r + 1;
    a[r] -= M - r + 1;
    b[r] += 1;
  };
  FOR(r, M) {
    Z [x, y] = e[r];
    while (lct.get(x) == lct.get(y)) {
      add(l, r + 1);
      Z [x, y] = e[l++];
      lct.cut(x, y);
    }
    lct.link(x, y);
  }
  a = pre_sum<0>(a);
  b = pre_sum<0>(b);
  FOR(i, M) a[i] += b[i] * (M - i);
  a.resize(M);
  print(a);
}
#include "YRS/Z_H/main.hpp"