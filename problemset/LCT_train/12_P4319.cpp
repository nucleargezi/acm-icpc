#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
using X = PII;
struct node {
  using np = node*;
  np l, r, p;
  int id;
  bool rev;
  X x, mx;

  node(int i = 0) : l(nullptr), r(l), p(l), id(i), rev(0) {}
  void upd() {
    x = mx;
    if (l) x = max(x, l->x);
    if (r) x = max(x, r->x);
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

  LCT(int N) : N(N), a(N) { FOR(i, N) a[i] = i; }

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
    y->l = y->l->p = nullptr, y->upd();
  }
  
  int expose(int x) {
    np t = expose(&a[x]);
    return t ? t->id : -1;
  }
  void evert(int x) { evert(&a[x]); }
  int get_rt(int x) { return get_rt(&a[x])->id; }
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
void Yorisou() {
  INT(N);
  vector<tuple<int, int, int, int, int>> e(N - 1);
  for (Z &[x, y, w, l, r] : e) {
    IN(x, y, w);
    --x, --y;
    l = 0, r = 32766;
  }
  INT(Q);
  FOR(Q) {
    INT(x, y, w, l, r);
    --x, --y, --l;
    e.ep(x, y, w, l, r);
  }
  LCT lct(N + N - 1 + Q);
  for (int t = N; Z [x, y, w, l, r] : e) {
    lct.a[t].mx = {w, t - N};
    ++t;
  }
  vector<int> I(N - 1 + Q);
  iota(all(I), 0);
  vector<PII> st;
  ll ans = 1;
  Z f = [&](Z &f, int l, int r, const vector<int> &I) -> void {
    if (l >= r) return;
    ll cp = ans;
    int m = (l + r) >> 1, t = len(st);
    vector<int> li, ri;
    for (int i : I) {
      Z [x, y, w, pl, pr] = e[i];
      if (pl <= l and pr >= r) {
        if (lct.get_rt(x) == lct.get_rt(y)) {
          Z [mx, id] = lct.prod(x, y);
          if (mx > w) {
            Z [xx, yy, k, j, l] = e[id];
            ans -= mx;
            lct.cut(xx, id + N);
            lct.cut(yy, id + N);
            st.ep(0, id);
            goto Link;
          }
        } else {
        Link:
          ans += w;
          lct.link(x, i + N);
          lct.link(y, i + N);
          st.ep(1, i);
        }
      } else {
        if (pl < m) li.ep(i);
        if (pr > m) ri.ep(i);
      }
    }
    if (l + 1 == r) print(ans);
    else f(f, l, m, li), f(f, m, r, ri);
    while (len(st) > t) {
      Z [op, id] = pop(st);
      Z [x, y, w, l, r] = e[id];
      if (op == 1) lct.cut(x, id + N), lct.cut(y, id + N);
      else lct.link(x, id + N), lct.link(y, id + N);
    }
    ans = cp;
  };
  f(f, 0, 32766, I);
}
#include "YRS/Z_H/main.hpp"