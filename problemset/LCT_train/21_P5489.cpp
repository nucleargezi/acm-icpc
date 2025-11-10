#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
struct MX {
  using X = int;
  static constexpr X op(X a, X b) { return a + b; }
  static constexpr X unit() { return 0; }
};
struct MA {
  using X = int;
  static constexpr X op(X a, X b) { return b == -1 ? a : b;; }
  static constexpr X unit() { return -1; }
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static constexpr X act(X x, A a, int sz) { return a == -1 ? x : a * sz; }
};
struct LCT {
  using X = MX::X;
  using A = MA::X;
  struct node {
    using np = node*;
    np l, r, p;
    int id, sz;
    bool rev;
    X x, mx;
    A lz;
    node(int i = 0) : l(nullptr), r(l), p(l),
                      id(i), sz(1), rev(0),
                      x(MX::unit()), mx(x), lz(MA::unit()) {}

    void upd() {
      sz = 1;
      x = mx;
      if (l) sz += l->sz, x = MX::op(x, l->x);
      if (r) sz += r->sz, x = MX::op(x, r->x);
    }
    void apply(A f) {
      mx = AM::act(mx, f, 1);
      x = AM::act(x, f, sz);
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
    void reverse() { rev ^= 1, swap(l, r); }
    void set(X x) { mx = x; }
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
  void evert(np x) {
    expose(x), x->reverse(), x->push();
  }
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
  void set(np x, X y) { evert(x), x->set(y); }
  int expose(int x) {
    np t = expose(&a[x]);
    return t ? t->id : -1;
  }
  void evert(int x) { evert(&a[x]); }
  int get_rt(int x) { return get_rt(&a[x])->id; }
  void link(int x, int y) { link(&a[x], &a[y]); }
  void cut(int x, int y) { cut(&a[x], &a[y]); }
  int get_fa(int x) {
    np p = get_fa(&a[x]);
    return p ? p->id : -1;
  }
  void set(int x, X y) { set(&a[x], y); }
  bool check(int x, int y) { return get_rt(x) == get_rt(y); }

  X prod(int x, int y) { return evert(x), expose(y), a[y].x; }
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
void Yorisou() {
  INT(N, Q);
  LCT A(N << 1), B(N << 1);
  int ans = 0, Ta = N, Tb = N;
  FOR(i, N, N << 1) A.a[i].mx = 1;
  FOR(i, N) B.a[i].mx = 1;
  FOR(Q) {
    INT(op, x, y);
    x ^= ans, y ^= ans;
    --x, --y;
    if (op == 1) {
      if (A.check(x, y)) {
        A.apply(x, y, 0);
        vector<int> pa;
        B.evert(x);
        while (y != x) {
          pa.ep(y);
          y = B.get_fa(y);
        }
        pa.ep(y);
        const int sz = len(pa);
        FOR(i, 1, sz) B.cut(pa[i - 1], pa[i]);
        for (int x : pa) B.link(x, Tb);
        ++Tb;
      } else {
        A.link(x, Ta), A.link(y, Ta);
        ++Ta;
        B.link(x, y);
      }
    } else if (op == 2) {
      print(A.check(x, y) ? ans = A.prod(x, y) : -1);
    } else if (op == 3) {
      print(A.check(x, y) ? ans = B.prod(x, y) : -1);
    }
  }
}
#include "YRS/Z_H/main.hpp"