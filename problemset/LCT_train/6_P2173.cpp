#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
using X = int;
struct node {
  using np = node *;
  np l, r, p;
  int id;
  bool rev;
  X x, mx;
  node(int i = 0) : l(nullptr), r(l), p(l),
                    id(i), rev(0),
                    x(-1), mx(-1) {}

  void upd() {
    x = mx;
    if (l) x = max(x, l->x);
    if (r) x = max(x, r->x);
  }
  void push() {
    if (not rev) return;
    if (l) l->reverse();
    if (r) r->reverse();
    rev = 0;
  }
  void reverse() { rev ^= 1, swap(l, r); }
  void set(int x) { mx = x; }
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
  np fa(np x) {
    expose(x), x->push();
    if (not x->l) return nullptr;
    x = x->l, x->push();
    while (x->r) x = x->r, x->push();
    return x;
  }
  void set(np p, X x) { return evert(p), p->set(x); }

  int expose(int x) {
    np t = expose(&a[x]);
    return t ? t->id : -1;
  }
  void evert(int x) { evert(&a[x]); }
  int get_rt(int x) { return get_rt(&a[x])->id; }
  void link(int x, int y) { link(&a[x], &a[y]); }
  void cut(int x, int y) { cut(&a[x], &a[y]); }
  int fa(int x) {
    np p = fa(&a[x]);
    return p ? p->id : -1;
  }
  void set(int p, X x) { set(&a[p], x); }
  int prod(int x, int y) { return evert(x), expose(y), a[y].x; }

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
      if (pp->l == p) pp ->l = x;
      else if (pp->r == p) pp->r = x;
    }
    x->p = pp, p->p = x;
    if (c) c->p = p;
  }

  bool have_edge(int x, int y) { return evert(x), fa(y) == x; }
  bool connect(int x, int y) { return get_rt(x) == get_rt(y); }
};
void Yorisou() {
  INT(N, M, C, Q);
  VEC(int, a, N);
  vector<LCT> lct(C, LCT(N));
  FOR(x, C) FOR(i, N) lct[x].set(i, a[i]);
  vector in(C, vector<int>(N));
  FOR(M) {
    INT(x, y, c);
    --x, --y;
    ++in[c][x], ++in[c][y];
    lct[c].link(x, y);
  }
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y);
      --x;
      FOR(i, C) lct[i].set(x, y);
    } else if (op == 1) {
      INT(x, y, w);
      --x, --y;
      int col = -1;
      FOR(i, C) if (lct[i].have_edge(x, y)) {
        col = i;
        break;
      }
      if (col == -1) {
        print("No such edge.");
      } else if (col == w) {
        print("Success.");
      } else if (max(in[w][x], in[w][y]) > 1) {
        print("Error 1.");
      } else if (lct[w].connect(x, y)) {
        print("Error 2.");
      } else {
        --in[col][x], --in[col][y];
        ++in[w][x], ++in[w][y];
        lct[col].cut(x, y);
        lct[w].link(x, y);
        print("Success.");
      }
    } else {
      INT(c, x, y);
      --x, --y;
      print(lct[c].connect(x, y) ? lct[c].prod(x, y) : -1);
    }
  }
}
#include "YRS/Z_H/main.hpp"