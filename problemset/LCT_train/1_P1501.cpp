#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"

constexpr int mod = 51061;

struct MX {
  using X = int;
  static constexpr X op(X L, X R) {
    L += R;
    if (L >= mod) L -= mod;
    return L;
  }
  static constexpr X unit() { return 0; }
};
struct MA {
  using X = pair<int, int>;
  static constexpr X op(X f, X g) {
    return {1ll * f.fi * g.fi % mod, (1ll * f.se * g.fi + g.se) % mod};
  } 
  static constexpr X unit() { return {1, 0}; }
  static constexpr X mul(int x) { return {x, 0}; }
  static constexpr X add(int x) { return {1, x}; }
};
using X = MX::X;
using A = MA::X;
struct AM {
  static constexpr X act(X x, A a, ll sz) {
    X r = 1ll * x * a.fi % mod + sz * a.se % mod;
    return r >= mod ? r - mod : r;
  }
};
struct node {
  using np = node*;
  np l, r, p;
  int id, sz;
  bool rev;
  X x, mx;
  A lz;

  node(int i = 0)
      : l(nullptr), r(l), p(l),
        id(i), sz(1), rev(0),
        x(MX::unit()), mx(x) {}

  void upd() {
    sz = 1;
    x = mx;
    if (l) sz += l->sz, x = MX::op(l->x, x);
    if (r) sz += r->sz, x = MX::op(x, r->x);
  }
  void apply(const A &f) {
    mx = AM::act(mx, f, 1);
    x = AM::act(x, f, sz);
    lz = MA::op(lz, f);
  }
  void push() {
    if (rev) {
      if (l) l->reverse();
      if (r) r->reverse();
      rev = 0;
    }
    if (lz != MA::unit()) {
      if (l) l->apply(lz);
      if (r) r->apply(lz);
      lz = MA::unit();
    }
  }
  void reverse() { rev ^= 1, swap(l, r); }
};
struct LCT {
  using np = node::np;
  int N;
  vector<node> a;
  LCT(int N = 0) : N(N), a(N) { FOR(i, 0, N) a[i] = node(i), a[i].mx = 1; }

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

  void link(int x, int y) { link(&a[x], &a[y]); }
  void cut(int x, int y) { cut(&a[x], &a[y]); }

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
  LCT lct(N);
  FOR(N - 1) {
    INT(x, y);
    --x, --y;
    lct.link(x, y);
  }
  FOR(Q) {
    CH(op);
    if (op == '+') {
      INT(x, y, c);
      --x, --y;
      lct.apply(x, y, MA::add(c));
    } else if (op == '-') {
      INT(x, y, xx, yy);
      --x, --y, --xx, --yy;
      lct.cut(x, y);
      lct.link(xx, yy);
    } else if (op == '*') {
      INT(x, y, c);
      --x, --y;
      lct.apply(x, y, MA::mul(c));
    } else {
      INT(x, y);
      --x, --y;
      print(lct.prod(x, y));
    }
  }
}
#include "YRS/Z_H/main.hpp"