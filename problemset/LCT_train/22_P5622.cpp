#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
using X = ll;
struct MX {
  using X = ll;
  static constexpr X op(X a, X b) { return a + b; }
  static constexpr X unit() { return 0; }
};
using A = bool;
struct MA {
  using X = A;
  static constexpr X op(X a, X b) { return b ? b : a; }
  static constexpr X unit() { return 0; }
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static constexpr X act(X x, A f, int) { return f ? 0 : x; }
};
struct LCT {
  struct node {
    using np = node *;
    np l, r, p;
    int id;
    bool rev;
    X x, mx;
    A lz;

    node(int i = 0) 
          : l(nullptr), r(l), p(l), 
            id(i), rev(0), x(0), mx(0), lz(0) {}

    void upd() {
      x = mx;
      if (l) x += l->x;
      if (r) x += r->x;
    }
    void apply(A f) {
      mx = AM::act(mx, f, 0);
      x = AM::act(x, f, 0);
      lz = MA::op(lz, f);
    }
    void push() {
      if (rev) {
        rev = 0;
        if (l) l->reverse();
        if (r) r->reverse();
      }
      if (lz) {
        if (l) l->apply(lz);
        if (r) r->apply(lz);
        lz = 0;
      }
    }
    void reverse() { rev ^= 1, swap(l, r); }
  };
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
  np get_fa(np x) {
    expose(x), x->push();
    if (not x->l) return nullptr;
    x = x->l, x->push();
    while (x->r) x = x->r, x->push();
    return x;
  }

  int expose(int x) {
    np t = expose(&a[x]);
    return t ? t->id : -1;
  }
  void evert(int x) { evert(&a[x]); }
  int get_rt(int x) { return get_rt(&a[x])->id; }
  void link(int x, int y) { link(&a[x], &a[y]); }
  void cut(int x, int y) { cut(&a[x], &a[y]); }
  int get_fa(int x) {
    np t = get_fa(&a[x]);
    return t ? t->id : -1;
  }
  X prod(int x, int y) { return evert(x), expose(y), a[y].x; }
  void multiply(int x, X y) { evert(x), a[x].mx += y; }
  void apply(int x, int y, A f) { evert(x), expose(y), a[y].apply(f); }

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
ull ans = 0;
int N, Q;
void make(int &x) {
  x ^= ans % N;
  if (x > N) x %= N;
  if (not x) x = 1;
}
void Yorisou() {
  IN(N, Q);
  LCT lct(N << 1);
  int t = N;
  FOR(Q) {
    INT(op, x, y);
    make(x), make(y);
    if (op == 1) {
      --x, --y;
      if (lct.get_rt(x) == lct.get_rt(y)) {
        vector<int> pa;
        lct.evert(x);
        while (x != y) {
          pa.ep(y);
          y = lct.get_fa(y);
        }
        pa.ep(x);
        const int sz = len(pa);
        FOR(i, 1, sz) lct.cut(pa[i - 1], pa[i]);
        for (int x : pa) lct.link(x, t);
        ++t;
      } else {
        lct.link(x, y);
      }
    } else if (op == 2) {
      --x;
      lct.multiply(x, y);
    } else {
      --x, --y;
      if (lct.get_rt(x) == lct.get_rt(y)) {
        print(ans = lct.prod(x, y));
        lct.apply(x, y, 1);
      } else {
        print(ans = 0);
      }
    }
  }
}
#include "YRS/Z_H/main.hpp"