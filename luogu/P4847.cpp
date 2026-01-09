#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/monoid/add.hpp"
#include "YRS/ds/basic/node_pool.hpp"

#define tests 0
#define fl 0
#define DB 10
template <typename monoid, int bsz = 1 << 18>
struct treap {
  using MX = monoid;
  using X = MX::X;
  struct node {
    node *l, *r, *p;
    X mx, x;
    uint sz;
  };
  using np = node *;
  
  node_pool<node, bsz> pool;

  void reset() { pool.reset(); }

  np get_rt(np x) {
    while (x->p) x = x->p;
    return x;
  }

  uint get_pos(np x) {
    uint sz = x->l ? x->l->sz : 0;
    while (x->p) {
      np p = x->p;
      if (x == p->r) {
        sz += 1 + (p->l ? p->l->sz : 0);
      }
      x = p;
    }
    return sz;
  }

  np newnode(const X &w) {
    return pool.gen(nullptr, nullptr, nullptr, w, w, 1u);
  }

  np cl(np x) { return x; }

  np merge(np l, np r) { return mer(l, r); }
  np merge(np a, np b, np c) { return mer(mer(a, b), c); }
  np merge(np a, np b, np c, np d) { return mer(mer(mer(a, b), c), d); }
  pair<np, np> split(np x, uint k) {
    if (not x) {
      assert(k == 0);
      return {nullptr, nullptr};
    }
    assert(0 <= k and k <= x->sz);
    return spl(x, k);
  }
  T3<np> split(np x, uint l, uint r) {
    np a, b;
    tie(x, b) = split(x, r);
    tie(x, a) = split(x, l);
    return {x, a, b};
  }
  X prod(np x, uint l, uint r) {
    if (l == r) return MX::unit();
    return _prod(x, l, r);
  }

 private:
  inline uint xo() {
    static uint x = 123'456'789, y = 362'436'069, 
                z = 521'288'629, w = 886'751'23;
    uint t = x ^ (x << 11);
    x = y, y = z, z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }
  void push(np x) {}
  void upd(np x) {
    x->sz = 1;
    x->x = x->mx;
    if (x->l) {
      x->l->p = x;
      x->sz += x->l->sz;
      x->x = MX::op(x->l->x, x->x);
    }
    if (x->r) {
      x->r->p = x;
      x->sz += x->r->sz;
      x->x = MX::op(x->x, x->r->x);
    }
  }
  np mer(np l, np r) {
    if (not l) return r;
    if (not r) return l;
    uint sl = l->sz, sr = r->sz;
    if (xo() % (sl + sr) < sl) {
      push(l), l = cl(l), l->r = mer(l->r, r);
      return upd(l), l;
    }
    push(r), r = cl(r), r->l = mer(l, r->l);
    return upd(r), r;
  }
  pair<np, np> spl(np x, uint k) {
    if (not x) return {nullptr, nullptr};
    push(x);
    uint sl = x->l ? x->l->sz : 0;
    if (k <= sl) {
      Z [l, r] = spl(x->l, k);
      x = cl(x), x->l = r, upd(x);
      return {l, x};
    }
    Z [l, r] = spl(x->r, k - (1 + sl));
    x = cl(x), x->r = l, upd(x);
    return {x, r};
  }
  X _prod(np x, uint l, uint r) {
    if (l == 0 and r == x->sz) return x->x;
    np lp = x->l;
    np rp = x->r;
    uint sl = lp ? lp->sz : 0;
    X s = MX::unit();
    if (l < sl) {
      X y = _prod(lp, l, min(r, sl));
      s = MX::op(s, y);
    }
    if (l <= sl and sl < r) s = MX::op(s, x->mx);
    uint k = 1 + sl;
    if (k < r) {
      X y = _prod(rp, max(k, l) - k, r - k);
      s = MX::op(s, y);
    }
    return s;
  }
};
using MX = monoid_add<ll>;
using DS = treap<MX>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  DS ds;
  vc<np> t(N);
  FOR(i, N) t[i] = ds.newnode(a[i]);
  FOR(Q) {
    CH(op);
    if (op == 'M') {
      INT(x, y);
      --x, --y;
      np rx = ds.get_rt(t[x]);
      np ry = ds.get_rt(t[y]);
      if (rx == ry) continue;
      np nt = ds.merge(ry, rx);
      nt->p = nullptr;
    } else if (op == 'D') {
      INT(x);
      --x;
      np r = ds.get_rt(t[x]);
      uint k = ds.get_pos(t[x]);
      Z [A, B] = ds.split(r, k);
      if (A) A->p = nullptr;
      if (B) B->p = nullptr;
    } else {
      INT(x, y);
      --x, --y;
      np rx = ds.get_rt(t[x]);
      np ry = ds.get_rt(t[y]);
      if (rx != ry) {
        print(-1);
      } else {
        uint px = ds.get_pos(t[x]);
        uint py = ds.get_pos(t[y]);
        uint l = min(px, py), r = max(px, py);
        ll ans = ds.prod(rx, l, r + 1);
        print(ans);
      }
    }
  }
}
#include "YRS/aa/main.hpp"