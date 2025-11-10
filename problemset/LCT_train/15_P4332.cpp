#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
vector<int> dis;
using X = struct dat {
  int id, x, p[4];
  int &operator[](int i) { return p[i]; }
};
struct MX {
  static X unit() { return {-1, 0, {-1, -1, -1, -1}}; }
  static X make(int i, int x) {
    X r = unit();
    r.id = i, r.x = x;
    r[x] = i;
    return r;
  }
  static int cp(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    return dis[a] > dis[b] ? a : b;
  }
  static X op(X a, X b) {
    X r = a;
    FOR(i, 4) r[i] = cp(a[i], b[i]);
    return r;
  }
};
using A = int;
static X act(X x, A a) {
  X r = x;
  r.x += a;
  FOR(i, 4) r[i] = -1;
  FOR(i, 4) if(i + a < 4 and i + a > -1) r[i + a] = x[i];
  return r;
}
struct node {
  using np = node *;
  np l, r, p;
  int id, sz;
  bool rev;
  X x, mx;
  A lz;

  node(int i = 0)
      : l(nullptr), r(l), p(l), id(i), sz(1), rev(0), lz(0) {}
  
  void upd() {
    sz = 1;
    x = mx;
    if (l) x = MX::op(x, l->x);
    if (r) x = MX::op(x, r->x);
  }
  void apply(A f) {
    mx = act(mx, f);
    x = act(x, f);
    lz += f;
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

  int expose(int x) {
    np t = expose(&a[x]);
    return t ? t->id : -1;
  }
  void evert(int x) { evert(&a[x]); }
  void link(int x, int y) { link(&a[x], &a[y]); }

  void apply(int x, int y, A f) { evert(x), expose(y), a[y].apply(f); }
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
  const int sz = N * 3 + 1;
  dis.resize(sz);
  LCT lct(sz);
  vector<int> fa(sz, -1);
  vector<vector<int>> v(sz);
  FOR(i, N) FOR(3) {
    INT(x);
    --x;
    fa[x] = i;
    v[i].ep(x);
  }
  vector<int> col(sz), s(sz);
  FOR(i, N, sz) IN(col[i]);
  FOR(i, N) if (s[i] > 1) col[i] = 1;
  Z f = [&](Z &f, int n) -> void {
    for (int x : v[n]) {
      dis[x] = dis[n] + 1;
      f(f, x);
      s[n] += col[x];
    }
    if(s[n] > 1) col[n] = 1;
  };
  f(f, 0);
  FOR(i, sz) lct.a[i].mx = MX::make(i, s[i]);
  FOR(i, sz) for (int x : v[i]) lct.link(i, x);

  INT(Q);
  int ans = col[0];
  FOR(Q) {
    INT(x);
    --x;
    col[x] ^= 1;
    int f = fa[x];
    Z dat = lct.prod(f, 0);
    int a = -1;
    FOR(i, 4) if (i != 2 - col[x]) a = MX::cp(a, dat[i]);
    if (a == -1) a = 0, ans ^= 1;
    lct.apply(f, a, col[x] ? 1 : -1);
    print(ans);
  }
}
#include "YRS/Z_H/main.hpp"