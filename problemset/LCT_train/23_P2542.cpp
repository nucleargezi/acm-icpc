#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/IO/fast_io.hpp"

// #define tests
using X = int;
struct MX {
  using X = int;
  static constexpr X op(X a, X b) { return a + b; }
  static constexpr X unit() { return 0; }
};
using A = int;
struct MA {
  using X = int;
  static constexpr X op(X a, X b) { return b == -1 ? a : b; }
  static constexpr X unit() { return -1; }
};
struct AM {
  static constexpr X act(X x, A a, int sz) { return a == -1 ? x : a * sz; }
};
struct LCT {
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
          x(MX::unit()), mx(x), lz(MA::unit()) {}
    void upd() {
      sz = 1, x = mx;
      if (l) sz += l->sz, x = MX::op(x, l->x);
      if (r) sz += r->sz, x = MX::op(x, r->x);
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
    void apply(A f) {
      mx = AM::act(mx, f, 1);
      x = AM::act(x, f, sz);
      lz = MA::op(lz, f);
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
  void evert(np x) {
    expose(x), x->reverse(), x->push();
  }
  np get(np x) {
    expose(x), x->push();
    while (x->l) x = x->l, x->push();
    return spl(x), x;
  }
  void link(np x, np y) {
    evert(x), expose(y);
    y->push(), x->p = y, y->r = x, y->upd();
  }
  int expose(int x) {
    np t = expose(&a[x]);
    return t ? t->id : -1;
  }
  void evert(int x) { evert(&a[x]); }
  int get(int x) { return get(&a[x])->id; }
  void link(int x, int y) { link(&a[x], &a[y]); }
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
  INT(N, M);
  VEC(PII, e, M);
  hash_map<int> mp;
  vector<char> vis(M, 1);
  for (int t = 0; Z &[x, y] : e) {
    --x, --y;
    if (x > y) swap(x, y);
    mp[ull(x) << 30 | y] = t++;
  }
  vector<T3<int>> quis;
  while (1) {
    INT(op);
    if (op == -1) break;
    INT(x, y);
    --x, --y;
    if (op == 0) {
      if (x > y) swap(x, y);
      int i = mp[ull(x) << 30 | y];
      vis[i] = 0;
    }
    quis.ep(op, x, y);
  }
  reverse(quis);
  LCT lct(N << 1);
  FOR(i, N, N << 1) lct.a[i].mx = 1;
  int t = N;
  FOR(i, M) if (vis[i]) {
    Z [x, y] = e[i];
    if (lct.get(x) == lct.get(y)) lct.apply(x, y, 0);
    else lct.link(t, x), lct.link(t++, y);
  }
  vector<int> ans;
  for (Z [op, x, y] : quis) {
    if (op == 0) {
      if (lct.get(x) == lct.get(y)) lct.apply(x, y, 0);
      else lct.link(t, x), lct.link(t++, y);
    } else {
      ans.ep(lct.prod(x, y));
    }
  }
  for (reverse(ans); int x : ans) print(x);
}
#include "YRS/Z_H/main.hpp"