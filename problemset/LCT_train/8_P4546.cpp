#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
constexpr int sz = 11;
using RE = double;
using X = array<RE, sz>;
struct fac {
  ll a[sz]{1};
  constexpr fac() { FOR(i, 1, sz) a[i] = a[i - 1] * i; }
  constexpr ll operator[](int i) const { return a[i]; }
} constexpr fac;
struct MX {
  using X = ::X;
  static constexpr X unit() { return {}; }
  static constexpr X make(int op, RE a, RE b) {
    X r{};
    if (op == 1) {
      RE t = 1, s = std::sin(b), c = std::cos(b);
      FOR(i, sz) {
        r[i] = t / fac[i] * ((i & 1) ? c : s) * ((i % 4 < 2) ? 1 : -1);
        t *= a;
      }
    } else if (op == 2) {
      RE t = 1, bs = std::exp(b);
      FOR(i, sz) {
        r[i] = t / fac[i] * bs;
        t *= a;
      }
    } else {
      r[0] = b, r[1] = a;
    }
    return r;
  }
  static constexpr X op(const X &L, const X &R) {
    X r{};
    FOR(i, sz) r[i] = L[i] + R[i];
    return r;
  }
  static constexpr bool commute = true;
};
struct node {
  using np = node *;
  np l, r, p;
  int id, sz;
  bool rev;
  X x, mx;

  node(int i = 0) : l(nullptr), r(l), p(l), id(i), sz(1), rev(0) {}

  void upd() {
    x = mx;
    if (l) x = MX::op(l->x, x);
    if (r) x = MX::op(x, r->x);
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
  using np = node *;
  int N;
  vector<node> a;

  LCT(int N = 0) : N(N), a(N) { FOR(i, N) a[i] = i; }

  np expose(np x) {
    np p = x, rp = nullptr;
    while (p) {
      spl(p);
      p->r = rp;
      p->upd();
      rp = p;
      p = p->p;
    }
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

  bool connect(int x, int y) { return get_rt(x) == get_rt(y); }

  void set(int x, X y) { evert(x), a[x].mx = y; }

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
  cout << std::fixed << std::setprecision(8);
  INT(N, Q);
  STR(type);
  LCT lct(N);
  FOR(i, N) {
    INT(op);
    REAL(a, b);
    lct.a[i].mx = MX::make(op, a, b);
  }
  FOR(Q) {
    STR(op);
    if (op[0] == 'a') {
      INT(x, y);
      lct.link(x, y);
    } else if (op[0] == 'd') {
      INT(x, y);
      lct.cut(x, y);
    } else if (op[0] == 'm') {
      INT(x, op);
      REAL(a, b);
      lct.set(x, MX::make(op, a, b));
    } else {
      INT(x, y);
      REAL(bs);
      if (lct.connect(x, y)) {
        Z poly = lct.prod(x, y);
        RE ans = 0, x = 1;
        FOR(i, sz) {
          ans += x * poly[i];
          x *= bs;
        }
        print(ans);
      } else {
        print("unreachable");
      }
    }
  }
}
#include "YRS/Z_H/main.hpp"